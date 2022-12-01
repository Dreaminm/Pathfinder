#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int start = 0, mid, end = size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mx_strcmp(s, arr[mid]) > 0)
		{
			start = mid + 1;
			(*count)++;
		}
		else if (mx_strcmp(s, arr[mid]) < 0)
		{
			end = mid - 1;
			(*count)++;
		}
		else if (mx_strcmp(s, arr[mid]) == 0)
		{
			(*count)++;
			return mid;
		}
	}
	if (start > end)
	{
		(*count) = 0;
		return -1;
	}
	return -1;
}


