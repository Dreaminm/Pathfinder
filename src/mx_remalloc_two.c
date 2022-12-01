#include "header.h"

int **mx_remalloc_two(int **arr, int size) {
    int length = 0, height = 0;

    for (int i = 0; arr[i] != NULL; i++)
    {
        height++;
    }

    int **res = (int**)malloc(sizeof(int*) * (height + 2));
    res[height + 1] = NULL;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; arr[i][j] != -1; j++)
        {
            length++;
        }
        res[i] = (int*)malloc(sizeof(int) * (length + 1));
        res[i][length] = -1;

        for (int j = 0; arr[i][j] != -1; j++)
        {
            res[i][j] = arr[i][j];
        }
        
        length = 0;
    }
    
    res[height] = (int*)malloc(sizeof(int) * (size + 1));
    res[height][size] = -1;

    return res;
}
