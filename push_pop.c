#include "monty.h"

/**
* push - Pushes or queues an item
*
*@head: Linked list head ptr
*@current_line: Current line in script
*/
void push(stack_t **head, unsigned int current_line)
{
	int i = 0;

	if (!process.arg)
	{
		fprintf(stderr, "L%u: usage: push integer", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	while (process.arg[i])
	{
		if (!isdigit(process.arg[i]) && process.arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer", current_line);
			shutdown();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (process.id == 1)
		add_dnodeint(head, atoi(process.arg));
	else
		add_dnodeint_end(head, atoi(process.arg));
}
/**
* pop - Pops the topmost element
*
*@head: Head of the linked list
*@current_line: Current line on the script
*/
void pop(stack_t **head, unsigned int current_line)
{
	stack_t *tmp = *head;

	if (!*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", current_line);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	free(tmp);
}
