#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b)) {
	int len = mx_list_size(list), rule = 0;
	t_list *cur = list;
	while (rule == 0)
	{
		for (int i = 0; i < len - 1; i++)
		{
			if (cmp(cur->data, cur->next->data) == true)
			{
				void *temp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = temp;
				rule = 1;
			}
			cur = cur->next;
		}
		if (rule == 1)
			rule = 0;
		else break;
	}
	return list;
}


