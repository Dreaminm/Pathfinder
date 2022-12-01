#include "header.h"

void mx_get_similar_error(char ***islands, int size) {
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (((mx_strcmp(islands[i][0], islands[j][0]) == 0) && (mx_strcmp(islands[i][1], islands[j][1]) == 0))
                || ((mx_strcmp(islands[i][0], islands[j][1]) == 0) && (mx_strcmp(islands[i][1], islands[j][0]) == 0)))
            {
                mx_print_error("error: duplicate bridges\n");
                exit(-1);
            }
        }
    }
}
