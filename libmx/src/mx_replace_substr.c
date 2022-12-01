#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	int count;
	if (str == NULL || sub == NULL || replace == NULL)
	{
		return NULL;
	}
	count = mx_count_substr(str, sub);
	char *changed = mx_strnew(mx_strlen(str) - mx_strlen(sub) * count + mx_strlen(replace) * count);
	char *cur = changed;
	char *used = mx_strstr(str, sub);
	while (used != NULL)
	{
		mx_strncpy(cur, str, used - str);
		cur += used - str;
		str = used + mx_strlen(sub);
		mx_strcat(cur, replace);
		used += mx_strlen(replace);
		used = mx_strstr(str, sub);
	}
	mx_strcat(cur, str);
	return changed;
}
