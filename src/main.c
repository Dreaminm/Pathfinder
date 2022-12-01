#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        mx_print_error("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    else mx_get_file_error(argv[1]);
    char *content = mx_read_file(argv[1]);
    mx_get_content_error(content);
    int size = mx_get_countoflines(content);
    int *lengthOfBridge = (int*)malloc(sizeof(int) * (size - 1));
    char ***islands = mx_getcontent_inarr(content, lengthOfBridge);  
    mx_get_length_error(lengthOfBridge, size);
    mx_pathfinder(islands, lengthOfBridge, size);
}
