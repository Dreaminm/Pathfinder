#include "libmx.h"

int mx_atoi(const char *str) {
    char *num = (char*) str;
    bool min = false;
    int count = 0;
    int numAtoi = 0;

    while (num[count] != '\0')
    {
        if ((num[count] >= 65 && num[count] <= 90) || (num[count] >= 97 && num[count] <= 122))
        {
            return 0;
        }
        count++;
    }
    
    count = 0;

    while (num[count] != '\0')
    {
        if (mx_isspace(num[count]))
        {
            count++;
            continue;
        }
        else if (num[count] == '-') {
            min = true;
            count++;
            continue;
        }
        else if (mx_isdigit(num[count]))
            break;
    }
    
    while (num[count] != '\0')
    {
        if (mx_isdigit(num[count]))
        {
            numAtoi *= 10;
            numAtoi += num[count] - 48;
            count++;
        }
        else break;
    }
    
    if (min)
    {
        numAtoi *= -1;
    }
    
    return numAtoi;
}
