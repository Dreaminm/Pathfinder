#include "header.h"

int **mx_delindex_two(int **candidates, int index) {
    int height = 0, length = 0;

    for (int i = 0; candidates[i] != NULL; i++)
    {
        height++;
    }
    
    int newHeight = height - 1;
    int count = 0;
    int **res = (int**)malloc(sizeof(int*) * (newHeight + 1));
    res[newHeight] = NULL;

    for (int i = 0; i < height; i++)
    {
        if (i != index)
        {
            for (int j = 0; candidates[i][j] != -1; j++)
            {
                length++;
            }
            
            res[count] = (int*)malloc(sizeof(int) * (length + 1));
            res[count][length] = -1;

            for (int j = 0; candidates[i][j] != -1; j++)
            {
                res[count][i] = candidates[i][j];
            }
            
            count++;
        }
        else continue;
    }
    
    return res;
}
