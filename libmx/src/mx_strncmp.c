#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2, int len) {
	int s1_len = mx_strlen(s1), s2_len = mx_strlen(s2);
	if (s1_len < len || s2_len < len)
	{
		return -1;
	}
	for (int i = 0; i < len && (s1[i] != '\0' || s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
		{
			return s1[i] - s2[i];
		}
	}
	return 0;
}
