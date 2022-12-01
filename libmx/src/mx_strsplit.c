#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
	int count = 0;
	bool rule = false;
	if (s == NULL)
	{
		return NULL;
	}
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c && rule == false)
		{
			count++;
			rule = true;
		} else if (s[i] == c)
		{
			rule = false;
		}
	}
	char **res = (char**)malloc(sizeof(char*) * (count + 1));
	res[count] = NULL;
	for (int i = 0; i < count; i++)
	{
		int len = 0;
		while (*s == c && *s != '\0')
		{
			s++;
		}
		char *temp = (char*)s;
		while (*s != c && *s != '\0')
		{
			len++;
			s++;
		}
		res[i] = mx_strnew(len);
		mx_strncpy(res[i], temp, len);
	}
	return res;
}

