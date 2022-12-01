#include "header.h"

int mx_get_count(const char *content) {
    int count = 0;

    while (content[count] != '\n')
    {
        count++;
    }

    char *num = mx_strnew(count);
    count = 0;

    while (content[count] != '\n')
    {
        num[count] = content[count];
        count++;
    }

    int numAtoi = mx_atoi(num);

    return numAtoi;
}
