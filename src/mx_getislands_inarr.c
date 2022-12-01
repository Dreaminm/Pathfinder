#include "header.h"

char ***mx_getislands_inarr(char *content) {
    int size = mx_get_countoflines(content) - 1, count = 0, length = 0, islandIndex = 0;
    char ***islands = (char***)malloc(sizeof(char**) * size);

    for (int i = 0; i < size; i++)
    {
        islands[i] = (char**)malloc(sizeof(char*) * 2);
    }

    while (content[count] != '\n')
    {
        count++;
    }

    count++;

    for (int i = 0; i < size; i++)
    {

        while (mx_isletter(content[count]))
        {
            length++;
            count++;
        }
        
        islands[i][0] = (char*)malloc(sizeof(char) * (length + 1));
        islands[i][0][length] = '\0';
        length = 0;
        count++;

        while (mx_isletter(content[count]))
        {
            length++;
            count++;
        }

        islands[i][1] = (char*)malloc(sizeof(char) * (length + 1));
        islands[i][1][length] = '\0';
        length = 0;
        count++;

        while (mx_isdigit(content[count]))
        {
            count++;
        }

        count++;
    }

    count = 0;

    while (content[count] != '\n')
    {
        count++;
    }
    count++;

    for (int i = 0; i < size; i++)
    {
        while (mx_isletter(content[count]))
        {
            islands[i][0][islandIndex] = content[count];
            
            count++;
            islandIndex++;
        }

        count++;
        islandIndex = 0;

        while (mx_isletter(content[count]))
        {
            islands[i][1][islandIndex] = content[count];
            
            count++;
            islandIndex++;
        }

        while (!mx_isletter(content[count]))
        {
            count++;
        }
        
        islandIndex = 0;
    }

    return islands;
}
