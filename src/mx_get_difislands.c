#include "header.h"

char **mx_get_difislands(char ***islands, int size) {
    char **temp = (char**)malloc(sizeof(char*) * size * 2);
    int tempSize = 2;
    bool sim = false;
    for (int i = 0; i < size * 2; i++)
    {
        temp[i] = NULL;
    }
    
    temp[0] = islands[0][0];
    temp[1] = islands[0][1];

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < tempSize; j++)
        {
            if (mx_strcmp(islands[i][0], temp[j]) == 0)
            {
                sim = true;
            }
        }

        if (!sim)
        {
            temp[tempSize] = islands[i][0];
            tempSize++;
        }

        sim = false;
        
        for (int j = 0; j < tempSize; j++)
        {
            if (mx_strcmp(islands[i][1], temp[j]) == 0)
            {
                sim = true;
            }
        }

        if (!sim)
        {
            temp[tempSize] = islands[i][1];
            tempSize++;
        }

        sim = false;
    }
    
    char **res = (char**)malloc(sizeof(char*) * (tempSize + 1));
    res[tempSize] = NULL;

    for (int i = 0; i < tempSize; i++)
    {
        res[i] = temp[i];
    }

    return res;
}
