#include "header.h"

Node *mx_copynodes(Node *ways, int size) {
    Node *res = (Node*)malloc(sizeof(Node) * size);

    for (int i = 0; i < size; i++)
    {
        res[i].value = ways[i].value;
        res[i].visited = ways[i].visited;
        res[i].index = ways[i].index;
    }
    
    return res;
}
