#include "header.h"

int **mx_getallpaths(Node *ways, int from, int to, int size, int **graph, char **difIslands) {
    Node *waysAlt = mx_copynodes(ways, size);
    int pathCount = 1, pathLength = 0;
    int **path = (int**)malloc(sizeof(int*) * (pathCount + 1));
    int neededLength = waysAlt[to].value;
    path[pathCount] = NULL;
    int cur = to;

    while (cur != from)
    {
        pathLength++;
        cur = waysAlt[cur].index;
    }

    pathLength++;
    path[pathCount - 1] = (int*)malloc(sizeof(int) * (pathLength + 1));
    path[pathCount - 1][pathLength] = -1;
    cur =  to;

    while (cur != from)
    {
        path[pathCount - 1][pathLength - 1] = cur;
        pathLength--;
        cur = waysAlt[cur].index;
    }

    path[pathCount - 1][pathLength - 1] = cur;
    pathLength--;   
    int **graphAlt = mx_copygraph(graph, size);
    int **candidates = (int**)malloc(sizeof(int*));
    candidates[0] = NULL;
    int *candidatesLength = (int*)malloc(sizeof(int));
    candidatesLength[0] = -1;
    int candidatesCount = 0;
    int *rootPath = (int*)malloc(sizeof(int));
    rootPath[0] = -1;
    int rootCount = 0;
    int delPath;

    for (int f = 0; f < 1; f++)
    {
        pathLength = 0;

        for (int i = 0; path[pathCount - 1][i] != to; i++)
        {
            rootPath = mx_remalloc_one(rootPath);
            rootCount++;
            rootPath[rootCount - 1] = path[pathCount - 1][i];
            
            for (int j = 0; path[j] != NULL; j++)
            {
                if ((delPath = mx_cmppath(path[j], rootPath)) != -1)
                {
                    graphAlt[path[j][delPath]][rootPath[delPath - 1]] = 0;
                    graphAlt[rootPath[delPath - 1]][path[j][delPath]] = 0;
                    
                    for (int k = 0; rootPath[k] != path[pathCount - 1][i]; k++)
                    {
                        for (int l = 0; l < size; l++)
                        {
                            graphAlt[rootPath[k]][l] = 0;
                            graphAlt[l][rootPath[k]] = 0;
                        }
                    }
                }
            }
            
            mx_reinitways(waysAlt, size, path[pathCount - 1][i]);  
            mx_getValueOfPath(waysAlt, graphAlt, difIslands);
            cur = to;
            from = path[pathCount - 1][i];

            if (waysAlt[to].index == to)
            {
                graphAlt = mx_copygraph(graph, size);
                continue;
            }
            
            candidatesCount++;

            for (int j = 0; path[pathCount - 1][j] != path[pathCount - 1][i]; j++)
            {
                pathLength++;
            }

            while (cur != from)
            {
                pathLength++;
                cur = waysAlt[cur].index;
            }

            pathLength++;
            candidates = mx_remalloc_two(candidates, pathLength);
            candidatesLength = mx_remalloc_one(candidatesLength);
            cur = to;

            for (int j = 0; path[pathCount - 1][j] != path[pathCount - 1][i]; j++)
            {
                candidates[candidatesCount - 1][j] = path[pathCount - 1][j];
            }

            while (cur != from)
            {
                candidates[candidatesCount - 1][pathLength - 1] = cur;
                pathLength--;
                cur = waysAlt[cur].index;
            }

            candidates[candidatesCount - 1][pathLength - 1] = cur;
            pathLength--;
            cur = candidates[candidatesCount - 1][0];
            int sum = 0;

            for (int j = 1; candidates[candidatesCount - 1][j] != -1; j++)
            {
                sum += graph[cur][candidates[candidatesCount - 1][j]];
                cur = candidates[candidatesCount - 1][j];
            }

            candidatesLength[candidatesCount - 1] = sum;
            graphAlt = mx_copygraph(graph, size);
        }
        
        pathLength = 0;
        for (int i = 0; candidates[i] != NULL; i++)
        {
            if (candidatesLength[i] == neededLength && !mx_alreadyused(path, candidates[i]))
            {
                for (int j = 0; candidates[i][j] != -1; j++)
                {
                    pathLength++;
                }
                
                pathCount++;
                path = mx_remalloc_two(path, pathLength);
                pathLength = 0;

                for (int j = 0; candidates[i][j] != -1; j++)
                {
                    path[pathCount - 1][j] = candidates[i][j];
                }
            }
        }
        
        free(rootPath);
        rootPath = (int*)malloc(sizeof(int));
        rootPath[0] = -1;
    }

    for (int i = 0; candidates[i] != NULL; i++)
    {
        free(candidates[i]);
        candidates[i] = NULL;
    }
    
    for (int i = 0; i < size; i++)
    {
        free(graphAlt[i]);
        graphAlt[i] = NULL;
    }

    free(graphAlt);
    free(waysAlt);
    free(candidates);
    free(candidatesLength);
    free(rootPath);
    mx_sortpath(path);

    return path;
}
