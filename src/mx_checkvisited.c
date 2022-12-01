#include "header.h"

bool mx_checkvisited(Node *node, int size) {
    for (int i = 0; i < size; i++)
    {
        if (!node[i].visited)
        {
            return false;
        }
    }
    
    return true;
}
