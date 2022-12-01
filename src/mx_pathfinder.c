#include "header.h"

void mx_pathfinder(char ***islands, int *lengthOfBridge, int size) {
    char **difIslands = mx_get_difislands(islands, size - 1);
    int numOfIslands = mx_getsize_arr(difIslands);
    int **graph = mx_getgraph(islands, difIslands, lengthOfBridge, size - 1);   
        
    Node **ways = (Node**)malloc(sizeof(Node*) * numOfIslands);

    for (int i = 0; i < numOfIslands; i++)
    {
        ways[i] = (Node*)malloc(sizeof(Node) * numOfIslands);
        for (int j = 0; j < numOfIslands; j++)
        {
            ways[i][j].value = 100000;
            ways[i][j].visited = false;
        }
    }
    
    mx_solvegraph(ways, graph, difIslands);

    for (int i = 0; i < numOfIslands; i++)
    {
        for (int j = i + 1; j < numOfIslands; j++)
        {
            mx_getpath(i, j, ways, graph, difIslands, numOfIslands);
        }
    }
}
