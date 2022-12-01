#include "libmx.h"

int mx_sqrt(int x) {
	double num = x / 2;
	double num2 = 0.0;
	if (x < 0)
		return 0;
	if (x == 1 || x == 0)
	{
		return x;
	}
	while (num2 - num != 0)
	{
		num2 = num;
		num = (x / num + num) / 2;
	}
	int temp = num;
	double check = temp;
	if (check == num)
	{
		return num;
	}
	return 0;
}


