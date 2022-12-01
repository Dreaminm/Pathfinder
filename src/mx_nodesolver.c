#include "header.h"

void mx_nodesolver(Node *ways, int **graph, char **difIslands, int index) {
    int *order = mx_getorder(graph, difIslands, index);

    for (int i = 0; order[i] != 0; i++)
    {
        if (!ways[index].visited && (ways[index].value + graph[index][order[i] - 1]) < ways[order[i] - 1].value)
        {
            ways[order[i] - 1].value = ways[index].value + graph[index][order[i] - 1];    
            ways[order[i] - 1].index = index;    
        }
    }

    ways[index].visited = true;
}
