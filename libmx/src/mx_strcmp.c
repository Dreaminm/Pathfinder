#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2) {
	int count = 0;
	while (s1[count] != '\0' || s2[count] != '\0')
	{
		if (s1[count] == s2[count])
		{
			if (s1[count + 1] != '\0' && s2[count + 1] == '\0')
			{
				return s1[count + 1];
			}
			else if (s2[count + 1] != '\0' && s1[count + 1] == '\0')
			{
				return -s2[count + 1];
			}
			count++;
			continue;
		}
		else if (s1[count] != s2[count])
		{
			return s1[count] - s2[count];
		}
	}
	return 0;
}


