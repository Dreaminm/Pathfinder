#include "header.h"

char ***mx_init_triplechar(int column, int length) {
    char ***res = (char***)malloc(sizeof(char**) * column);
    
    for (int i = 0; i < column; i++)
    {
        res[i] = (char**)malloc(sizeof(char*) * length);
        for (int j = 0; j < length; j++)
        {
            res[i][j] = NULL;
        }
    }
    
    return res;
}
