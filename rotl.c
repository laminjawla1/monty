#include "monty.h"

/**
*rotl - Rotates the stack to the top.
*
*@head: Head of the linked list
*@l: Current_line
*/
void rotl(stack_t **head, unsigned int __attribute__((unused))l)
{
	stack_t *start, *end;
	int n;

	start = end = *head;
	while (end->next)
		end = end->next;
	while (start < end)
	{
		n = start->n;
		start->n = end->n;
		end->n = n;

		start = start->next;
		end = end->prev;
	}
}
