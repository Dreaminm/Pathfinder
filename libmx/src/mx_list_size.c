#include "libmx.h"

int mx_list_size(t_list *list) {
	int count = 1;
	if (list == NULL)
	{
		return 0;
	}
	while (list->next != NULL)
	{
		list = list->next;
		count++;
	}
	return count;
}
