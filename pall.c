#include "monty.h"

/**
* pall - Prints the stack
*
*@head: Stack head
*@current_line: Line number
*/
void pall(stack_t **head, unsigned int __attribute__((unused))current_line)
{
	stack_t *h = *head;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
