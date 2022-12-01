#include "header.h"

void mx_sortpath(int **path) {
    bool rule = true;

    while (rule)
    {
        for (int i = 0; path[i + 1] !=  NULL; i++)
        {
            if (mx_sortarr_one(path[i], path[i + 1]) > 0)
            {
                int *temp = path[i];
                path[i] = path[i + 1];
                path[i + 1] = temp;
                rule = false;
            }
        }

        if (!rule)
        {
            rule = true;
        }
        else break;
    }
}
