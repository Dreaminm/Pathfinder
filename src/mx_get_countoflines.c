#include "header.h"

int mx_get_countoflines(char *content) {
    int count = 0, lineCount = 0;

    while (content[count] != '\0')
    {
        if (content[count] == '\n')
        {
            lineCount++;
        }
        
        count++;
    }
    
    return lineCount;
}
