#include "header.h"

int **mx_copygraph(int **graph, int size) {
    int **graphAlt = (int**)malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++)
    {
        graphAlt[i] = (int*)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
        {
            graphAlt[i][j] = graph[i][j];
        }
    }
    
    return graphAlt;
}
