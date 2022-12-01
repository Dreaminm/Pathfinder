#include "header.h"

void mx_get_file_error(const char *file) {
    int fd = open(file, O_RDONLY);

    if (fd == -1)
    {
        mx_print_error("error: file ");
        mx_print_error(file);
        mx_print_error(" does not exist\n");
        exit(-1);
    }
    char c;
    int bytes, rule = 0;
    while ((bytes = read(fd, &c, sizeof(c))) > 0)
    {
        rule = 1;
    }
    if (rule == 0)
    {
        mx_print_error("error: file ");
        mx_print_error(file);
        mx_print_error(" is empty\n");
        exit(-1);
    }

    close(fd);
}
