#include "libmx.h"

void mx_str_reverse(char *s) {
	int length = 0;
	if (s == NULL)
	{
		return;
	}
	while (s[length] != '\0')
	{
		length++;
	}
	for (int i = 0; i < length / 2; i++)
	{
		char temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;
	}
}
