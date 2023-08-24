#include "monty.h"

/**
* swap - Swaps the top two elements of the stack
*
*@head: Head of the linked list
*@current_line: Current line in the script
*/
void swap(stack_t **head, unsigned int current_line)
{
	int tmp;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "%u: can't swap, stack too short\n", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
