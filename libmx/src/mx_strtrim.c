#include "libmx.h"

char *mx_strtrim(const char *str) {
	int length;
	if (str == NULL)
	{
		return NULL;
	}
	while (mx_isspace(*str))
	{
		str++;
	}
	length = mx_strlen(str);
	while (length > 0 && mx_isspace(str[length - 1]))
	{
		length--;
	}
	char *res = mx_strnew(length);
	mx_strncpy(res, str, length);
	return res;
}
