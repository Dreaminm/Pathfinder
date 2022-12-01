#include "libmx.h"

char *mx_itoa(int number) {
	int count = 0;
	int use = number;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	char *res = (char*)malloc(sizeof(char) * (count + 1));
	res[count] = '\0';
	for (int i = count - 1; i >= 0; i--)
	{
		res[i] = 48 + (use % 10);
		use /= 10;
	}
	return res;
}

