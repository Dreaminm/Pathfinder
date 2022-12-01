#include "libmx.h"

void mx_print_error(const char *str) {
    write(2, str, sizeof(char) * mx_strlen(str));
}
