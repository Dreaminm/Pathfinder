#include "libmx.h"

int partition(char **arr, int left, int right, int *count) {
	int r = right;
	int l = left;
	char *pivot = arr[left + (right - left) / 2];
	while (l <= r)
	{
		while (mx_strlen(arr[l]) < mx_strlen(pivot))
		{
			l++;
		}
		while (mx_strlen(arr[r]) > mx_strlen(pivot))
		{
			r--;
		}
		if (l <= r)
		{
			char *temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
			(*count)++;
		}
	}
	return l;
}

int mx_quicksort(char **arr, int left, int right) {
	static int count;
    	if (arr == NULL) {
       	 return -1;
    	}
    	if (left < right)
    	{
    		int divideIndex = partition(arr, left, right, &count);
    		mx_quicksort(arr, left, divideIndex - 1);
    		mx_quicksort(arr, divideIndex, right);
    	}
    	return count;
}

