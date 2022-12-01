#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	if (sub == NULL || str == NULL)
	{
		return -1;
	}
	if (*sub == '\0')
	{
		return 0;
	}
	int sub_len = mx_strlen(sub), count = 0;
	char *temp = (char*)str;
	temp = mx_strstr(temp, sub);
	while (temp != 0)
	{
		temp = mx_strstr(temp + sub_len, sub);
		count++;
	}
	return count;
}
