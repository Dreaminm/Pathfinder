#include "libmx.h"

char *mx_strdup(const char *s1) {
	int length = mx_strlen(s1);
	char *res = mx_strnew(length);
	for (int i = 0; i < length; i++)
	{
		res[i] = s1[i];
	}
	return res;
}
