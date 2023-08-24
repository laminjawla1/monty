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
/**
* pint - Peeks and print the topmost element
*
*@head: Head of the linked list
*@current_line: Current line in the script
*/
void pint(stack_t **head, unsigned int current_line)
{
	if (!*head)
		handle_error("can't pint, stack empty", current_line);
	printf("%d\n", (*head)->n);
}
