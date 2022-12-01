#include "header.h"

int mx_cmppath(int *path, int *rootPath) {
    int i;
    for (i = 0; rootPath[i] != -1; i++)
    {
        if (rootPath[i] != path[i])
            return -1;
    }
    
    return i;
}
