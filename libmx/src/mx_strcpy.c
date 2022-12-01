#include <stdio.h>

char *mx_strcpy(char *dst, const char *src) {
	int count = 0;
	while (src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	return dst;
}


