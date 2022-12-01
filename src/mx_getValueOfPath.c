#include "header.h"

void mx_getValueOfPath(Node *ways, int **graph, char **difIslands) {
    int size = mx_getsize_arr(difIslands);

    while (!mx_checkvisited(ways, size))
    {
        int index = mx_getindex(ways, size);
        mx_nodesolver(ways, graph, difIslands, index);
    }
}
