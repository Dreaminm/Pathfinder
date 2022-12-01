#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	int s1_len = mx_strlen(s1), s2_len = mx_strlen(s2), len = s1_len + s2_len;
	if (s1 == NULL && s2 == NULL)
	{
		return NULL;
	}
	if (s1 == NULL && s2 != NULL)
	{
		char *res = mx_strnew(s2_len);
		return mx_strcpy(res, s2);
	}
	else if (s1 != NULL && s2 == NULL)
	{
		char *res = mx_strnew(s1_len);
		return mx_strcpy(res, s1);
	}
	char *res = mx_strnew(len);
	int pos;
	for (pos = 0; pos < s1_len; pos++)
	{
		res[pos] = s1[pos];
	}
	for (int i = pos; i < len; i++)
	{
		res[i] = s2[i];
	}
	return res;
}	
