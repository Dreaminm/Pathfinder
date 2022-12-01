#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
	int rule = 0, count = 0;
	while (rule == 0)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (mx_strcmp(arr[i], arr[i + 1]) > 0)
			{
				char *temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				count++;
				rule = 1;
			}
		}
		if (rule == 1)
		{
			rule = 0;
		}
		else break;
	}
	return count;
}


