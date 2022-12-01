#include "header.h"

int *mx_remalloc_one(int *arr) {
    int height = 0;

    for (int i = 0; arr[i] != -1; i++)
    {
        height++;
    }
    
    int *res = (int*)malloc(sizeof(int) * (height + 2));
    res[height + 1] = -1;

    for (int i = 0; i < height; i++)
    {
        res[i] = arr[i];
    }
    
    return res;
}
