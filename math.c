#include "monty.h"

/**
* add - Adds the top two elements of the stack
*
*@head: Head of the list
*@current_line: Current line
*/
void add(stack_t **head, unsigned int current_line)
{
	if (dlist_len(*head) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	pop(head, current_line);
}
/**
* sub - Subtract the top two elements of the stack
*
*@head: Head of the stack
*@current_line: Current line
*/
void sub(stack_t **head, unsigned int current_line)
{
	if (dlist_len(*head) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", current_line);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, current_line);
}
