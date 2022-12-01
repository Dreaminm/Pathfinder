#include "header.h"

int* mx_getlengths_inarr(char *content, int size) {
    int *lengthOfBridge = (int*)malloc(sizeof(int) * size);
    int count = 0, length = 0;

    while (content[count] != '\n')
    {
        count++;
    }

    count++;

    for (int i = 0; i < size; i++)
    {

        while (mx_isletter(content[count]))
        {
            count++;
        }
        
        count++;

        while (mx_isletter(content[count]))
        {
            count++;
        }

        count++;
        int contIndex = count, numIndex = 0;

        while (mx_isdigit(content[count]))
        {
            length++;
            count++;
        }

        char *num = (char*)malloc(sizeof(char) * (length + 1));
        num[length] = '\0';

        while (mx_isdigit(content[contIndex]))
        {
            num[numIndex] = content[contIndex];
            numIndex++;
            contIndex++;
        }
        
        lengthOfBridge[i] = mx_atoi(num);
        length = 0;
        count++;
    }

    return lengthOfBridge;
}
