#include "monty.h"

/**
* free_dlist - Frees the dynamically allocated linked list
*
*@head: Pointer to the head of linked list
*/
void free_dlist(stack_t *head)
{
	stack_t *tmp = head;

	while (tmp)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
