#include "header.h"

int **mx_getgraph(char ***islands, char **difIslands, int *lengthOfBridge, int height) {
    int size = mx_getsize_arr(difIslands);

    int **res = (int**)malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++)
    {
        res[i] = (int*)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
        {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                res[i][j] = 0;
            }
            else 
            {
                for (int k = 0; k < height; k++)
                {
                    if ((mx_strcmp(difIslands[i], islands[k][0]) == 0 && mx_strcmp(difIslands[j], islands[k][1]) == 0)
                        || (mx_strcmp(difIslands[i], islands[k][1]) == 0 && mx_strcmp(difIslands[j], islands[k][0]) == 0))
                    {
                        res[i][j] = lengthOfBridge[k];
                    }
                }
            }
        }
    }
    
    return res;
}

