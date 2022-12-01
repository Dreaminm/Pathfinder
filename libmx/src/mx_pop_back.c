#include "libmx.h"

void mx_pop_back(t_list **head) {
	if (*head == NULL || head == NULL)
	{
		return;
	}
	t_list *cur = *head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	free(cur);
	cur = NULL;
}
