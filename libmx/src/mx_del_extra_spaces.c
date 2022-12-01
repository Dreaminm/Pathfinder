#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
	char *trimmed = mx_strtrim(str);
	char *used_str = trimmed;
	char *main_str = trimmed;
	if (trimmed == NULL)
	{
		return NULL;
	}
	while (*used_str != '\0')
	{
		if (!mx_isspace(*used_str))
		{
			if (used_str != trimmed && mx_isspace(*(used_str - 1)))
			{
				*main_str = ' ';
				main_str++;
			}
			*main_str = *used_str;
			main_str++;
		}
		used_str++;
	}
	char *res = mx_strnew(main_str - trimmed);
	mx_strncpy(res, trimmed, main_str - trimmed);
	mx_strdel(&trimmed);
	return res;
}
