#include "header.h"

int mx_getindex(Node *ways, int size) {
    int min;

    for (int i = 0; i < size; i++)
    {
        if (!ways[i].visited)
        {
            min = i;
            break;
        }
    }
    

    for (int i = 0; i < size; i++)
    {
        if (!ways[i].visited && ways[i].value < ways[min].value)
        {
            min = i;
        }
    }
    
    return min;
}
