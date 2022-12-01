#include "header.h"

int mx_sortarr_one(int *arr1, int *arr2) {
    int length1 = 0;
    int length2 = 0;

    for (int i = 0; arr1[i] != -1; i++)
    {
        length1++;
    }
    
    for (int i = 0; arr2[i] != -1; i++)
    {
        length2++;
    }

    for (int i = 0; arr1[i] != -1 || arr2[i] != -1; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return arr1[i] - arr2[i];
        }
    }

    if (length1 != length2)
    {
        return length1 - length2;
    }
        
    return 0;
}
