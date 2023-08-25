#include "monty.h"

/**
*rotl - Rotates the stack to the top.
*
*@head: Head of the linked list
*@current_line: Current_line
*/
void rotl(stack_t **head, unsigned int current_line)
{
	int n;

	if (!*head || !(*head)->next)
		return;
	n = (*head)->n;
	pop(head, current_line);
	add_dnodeint_end(head, n);
}
