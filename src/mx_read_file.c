#include "header.h"

char *mx_read_file(const char *file) {
    int fd = open(file, O_RDONLY);
    char c;
    int bytes, count = 0;

    while ((bytes = read(fd, &c, sizeof(c))) > 0)
    {
        count++;
    }

    close(fd);

    fd = open(file, O_RDONLY);
    char *content = mx_strnew(count);
    count = 0;

    while ((bytes = read(fd, &c, sizeof(c))) > 0)
    {
        content[count] = c;
        count++;
    }
    
    close(fd);
    return content;
}
