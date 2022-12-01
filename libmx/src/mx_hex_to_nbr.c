#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	int len = 0;
	long res = 0;
	char *alph = "ABCDEF";
	while (hex[len] != '\0')
	{
		len++;
	}
	for (int i = 0; i < len; i++)
	{
		long pow = 1;
		long use = 0;
		for (int j = 0; j < len - i - 1; j++)
		{
			pow *= 16;
		}
		if (hex[i] >= 48 && hex[i] <= 57)
		{
			use = hex[i] - 48;
		}
		else
		{
			for (int k = 0; k < 6; k++)
			{
				if (hex[i] == alph[k] || hex[i] == alph[k] + 32) 
				{
					use = 10 + k;
				}	
			}
		}
		res += use * pow;
	}
	return res;
}


