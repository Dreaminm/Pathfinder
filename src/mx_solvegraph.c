#include "header.h"

void mx_solvegraph(Node **ways, int **graph, char **difIslands) {
    int numOfIslands = mx_getsize_arr(difIslands);

    for (int i = 0; i < numOfIslands; i++)
    {
        ways[i][i].value = 0;
        ways[i][i].index = i;
        mx_getValueOfPath(ways[i], graph, difIslands);
    }
}
