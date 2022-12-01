#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	void *changed;
	if (ptr == NULL)
	{
		changed = malloc(size);
		return changed; 
	}
	size_t prev = malloc_size(ptr);
	if (prev >= size)
	{
		return ptr;
	}
	changed = malloc(size);
	changed = mx_memcpy(changed, ptr, prev);
	free(ptr);
	return changed;
}
