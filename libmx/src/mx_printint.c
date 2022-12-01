#include "libmx.h"

void mx_printint(int n) {
	int sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	long temp = n;
	long res = n % 10;
	int count = 0;
	res *= 10;
	if (n == 0)
	{
		mx_printchar(48);
		return;
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	while (temp % 10 == 0)
	{
		count++;
		temp /= 10;
	}	
	temp = n / 10;
	while (temp != 0)
	{
		res += temp % 10;
		res *= 10;
		temp /= 10;
	}
	res /= 10;
	if (sign == -1)
	{
		mx_printchar(45);
	}
	while (res != 0)
	{
		mx_printchar((res % 10) + 48);
		res /= 10;
	}
	for (int i = 0; i < count; i++)
	{
		mx_printchar(48);
	}
}


