#include "header.h"

void mx_get_content_error(const char *content) {
    int numAtoi = mx_get_countoflines((char*)content) - 1, count = 0;
    int num = mx_get_count(content);
    int symbCount = 0;
    char ***islands = mx_getislands_inarr((char*)content);
    char **difIslands = mx_get_difislands(islands, numAtoi);
    int length = 0;

    while (difIslands[length] != NULL)
    {
        length++;
    }
    
    if (num <= 0)
    {
        mx_print_error("error: line 1 is not valid\n");
        exit(-1);
    }

    for (int i = 0; i < numAtoi; i++)
    {
        if (mx_strcmp(islands[i][0], islands[i][1]) == 0)
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 2));
            mx_print_error(" is not valid\n");
            exit(-1);
        }
    }    

    while (content[count] != '\n')
    {
        count++;
    }
    count++;

    for (int i = 1; i <= numAtoi; i++)
    {
        if (!mx_isletter(content[count]))
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }
        while (mx_isletter(content[count]))
        {
            count++;
        }
        if (content[count] != '-')
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }
        while (content[count] == '-')
        {
            count++;
            symbCount++;
        }
        if (symbCount != 1)
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }    
        symbCount = 0;
        if (!mx_isletter(content[count]))
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }
        while (mx_isletter(content[count]))
        {
            count++;
        }
        if (content[count] != ',')
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }
        while (content[count] == ',')
        {
            count++;
            symbCount++;
        }
        if (symbCount != 1)
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }  
        if (!mx_isdigit(content[count]))
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }
        while (mx_isdigit(content[count]))
        {
            count++;
        }
        if (content[count] != '\n')
        {
            mx_print_error("error: line ");
            mx_print_error(mx_itoa(i + 1));
            mx_print_error(" is not valid\n");
            exit(-1);
        }
        symbCount = 0;
        count++;
    }

    if (num != length)
    {
        mx_print_error("error: invalid number of islands\n");
        exit(-1);
    }

    mx_get_similar_error(islands, numAtoi);
}
