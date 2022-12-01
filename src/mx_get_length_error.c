#include "header.h"

void mx_get_length_error(int *lengthOfBridge, int size) {
    long int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += lengthOfBridge[i];
    }
    
    if (sum > INT_MAX)
    {
        mx_print_error("error: sum of bridges lengths is too big\n");
        exit(-1);
    }
}
