#include "header.h"

int mx_getsize_arr(char **arr) {
    int count = 0;

    while (arr[count] != NULL)
    {
        count++;
    }

    return count;  
}
