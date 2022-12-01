#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void* little, size_t little_len) {
	if (little_len == 0)
	{
		return NULL;
	}
	void *ptr = mx_memchr(big, *(unsigned char*)little, big_len);
	size_t diff = big_len - ((unsigned char*)ptr - (unsigned char*)big);
	while (ptr != NULL && diff >= little_len)
	{
		if (mx_memcmp(ptr, little, little_len) == 0)
		{
			return ptr;
		}
		ptr = mx_memchr(big, *(unsigned char*)little, big_len);
		diff = big_len - ((unsigned char*)ptr - (unsigned char*)big);
	}
	return NULL;
}
