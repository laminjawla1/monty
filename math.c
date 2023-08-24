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
		fprintf(stderr, "L%u: can't sub, stack too short\n", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, current_line);
}
/**
* _div - Divides the second top element of the stack
*	by the top element of the stack
*
*@head: Head of the stack
*@current_line: Current line
*/
void _div(stack_t **head, unsigned int current_line)
{
	if (dlist_len(*head) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	pop(head, current_line);
}
