#include "libmx.h"

bool mx_isletter(char c) {
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
