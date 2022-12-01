#include "header.h"

int mx_get_numofbridges(char ***islands, int size) {
    int bridges = size - 1;
    
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            if (((mx_strcmp(islands[i][0], islands[j][0]) == 0) && (mx_strcmp(islands[i][1], islands[j][1]) == 0))
                || ((mx_strcmp(islands[i][0], islands[j][1]) == 0) && (mx_strcmp(islands[i][1], islands[j][0]) == 0)))
            {
                bridges--;
            }
        }
    }
    
    return bridges;
}
