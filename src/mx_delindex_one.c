#include "header.h"

int *mx_delindex_one(int *candidatesLength, int index) {
    int height = 0;

    for (int i = 0; candidatesLength[i] != -1; i++)
    {
        height++;
    }
    
    int newHeight = height - 1;

    int *res = (int*)malloc(sizeof(int) * (newHeight + 1));
    res[newHeight] = -1;
    int count = 0;

    for (int i = 0; candidatesLength[i] != -1; i++)
    {
        if (i != index)
        {
            res[count] = candidatesLength[i];
            count++;
        }
        else continue;
    }
    
    return res;
}
