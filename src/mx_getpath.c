#include "header.h"

void mx_getpath(int from, int to, Node **ways, int **graph, char **difIslands, int numOfIslands) {    
    int count = 0;      
    int **path = mx_getallpaths(ways[from], from, to, numOfIslands,graph, difIslands);
    int cur = from;
    
    for (int i = 0; path[i] != NULL; i++)
    {
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(difIslands[from]);
        mx_printstr(" -> ");
        mx_printstr(difIslands[to]);
        mx_printchar('\n');

        mx_printstr("Route: ");
        mx_printstr(difIslands[from]);

        for (int j = 1; path[i][j] != -1; j++)
        {
            mx_printstr(" -> ");
            mx_printstr(difIslands[path[i][j]]);
        }
        
        mx_printchar('\n');

        mx_printstr("Distance: ");
        mx_printint(graph[path[i][0]][path[i][1]]);
        cur = path[i][1];

        for (int j = 2; path[i][j] != -1; j++)
        {
            count++;
            mx_printstr(" + ");
            mx_printint(graph[cur][path[i][j]]);
            cur = path[i][j];
        }

        if (count != 0)
        {
         
            mx_printstr(" = ");
            mx_printint(ways[from][to].value);
        }

        mx_printchar('\n');
        mx_printstr("========================================\n");
        count = 0;
    }
}
