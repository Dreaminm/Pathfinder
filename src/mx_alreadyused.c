#include "header.h"

bool mx_alreadyused(int **arr, int *cmpred) {
    int arrLength = 0, cmpredLength = 0, length = 0;
    bool rule = true;

    for (int i = 0; cmpred[i] != -1; i++)
    {
        cmpredLength++;
    }
    
    for (int i = 0; arr[i] != NULL; i++)
    {
        arrLength++;
    }
    
    for (int i = 0; arr[i] != NULL; i++)
    {
        for (int j = 0; arr[i][j] != -1; j++)
        {
            length++;
        }
        
        if (cmpredLength == length)
        {
            for (int j = 0; arr[i][j] != -1; j++)
            {
                if (cmpred[j] != arr[i][j])
                    rule = false;
            }
        }
        else rule = false;

        if (rule)
            return rule;
        else
        {
            length = 0;
            rule = true;
        }
    }
    
    return false;
}
