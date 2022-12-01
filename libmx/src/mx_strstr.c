#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
	int length = mx_strlen(needle);
	if (length == 0)
	{
		return (char*)haystack;
	}
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			if (mx_strncmp(haystack, needle, length) == 0)
			{
				return (char*)haystack;
			}
			haystack++;
		}
		else haystack++;
	}
	return NULL;
}
