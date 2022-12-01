#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	char *alph = "abcdef";
	if (nbr < 16)
	{
		char *ans = mx_strnew(1);
		if (nbr <= 9)
			ans[0] = nbr + 48;
		else ans[0] = alph[nbr - 10];
		return ans;
	}
	long res = nbr / 16;
	int size = 2;
	while (res >= 16)
	{
		res /= 16;
		size++;
	}
	int count = 0;
	char *ans = mx_strnew(size);
	res = nbr;
	long ch;
	while (res >= 16)
	{
		ch = res % 16;
		res /= 16;
		if (ch <= 9)
		ans[count] = ch + 48;
		else ans[count] = alph[ch - 10];
		count++;
	}
	if (res <= 9)
	ans[count] = res + 48;
	else ans[count] = alph[ch - 10];
	mx_str_reverse(ans);
	return ans;
}
