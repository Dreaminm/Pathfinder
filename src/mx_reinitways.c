#include "header.h"

void mx_reinitways(Node *ways, int size, int index) {
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            ways[i].value = 0;
        }
        else 
        {
            ways[i].value = 100000;
        }
        ways[i].visited = false;
        ways[i].index = i;
    }
    
}
