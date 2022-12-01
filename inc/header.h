#pragma once 
 
#include "libmx.h" 
 
typedef struct Node {
    int value;
    bool visited;
    int index;
}Node;

void mx_get_file_error(const char *file);
void mx_get_content_error(const char *content);
void mx_get_similar_error(char ***islands, int size);
void mx_get_length_error(int *lengthOfBridge, int size);
void mx_pathfinder(char ***islands, int *lengthOfBridge, int size);
void mx_solvegraph(Node **ways, int **graph, char **difIslands);
void mx_getValueOfPath(Node *ways, int **graph, char **difIslands);
void mx_nodesolver(Node *ways, int **graph, char **difIslands, int index);
void mx_getpath(int from, int to, Node **ways, int **graph, char **difIslands, int numOfIlsands);
void mx_reinitways(Node *ways, int size, int index);
void mx_sortpath(int **path);

char *mx_read_file(const char *file);
char ***mx_getcontent_inarr(const char *content, int *lengthOfBridge);
char ***mx_getislands_inarr(char *content);
char **mx_get_difislands(char ***islands, int size);
char ***mx_init_triplechar(int column, int length);

int mx_get_count(const char *content);
int mx_get_numofbridges(char ***islands, int size);
int mx_get_countoflines(char *content);
int *mx_getlengths_inarr(char *content, int size);
int mx_getsize_arr(char **arr);
int **mx_getgraph(char ***islands, char **difIslands, int *lengthOfBridge, int height);
int *mx_getorder(int **graph, char **difIslands, int index); 
int mx_getindex(Node *ways, int size); 
int **mx_getpath_arr(Node *ways, int to, int **graph, char **difIslands);
int **mx_getallpaths(Node *ways, int from, int to, int size, int **graph, char **difIslands);
int **mx_copygraph(int **graph, int size);
int **mx_remalloc_two(int **arr, int size);
int *mx_remalloc_one(int *arr);
int mx_sortarr_one(int *arr1, int *arr2);
int mx_cmppath(int *path, int *rootPath);
int *mx_delindex_one(int *candidatesLength, int index);
int **mx_delindex_two(int **candidates, int index);

bool mx_checkvisited(Node *node, int size);
bool mx_alreadyused(int **arr, int *cmpred);

Node *mx_copynodes(Node *ways, int size);
