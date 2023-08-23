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
	int item;
	extern process_t process;

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
	item = atoi(process.arg);
	if (process.id == 1)
		add_dnodeint(head, item);
	else
		add_dnodeint_end(head, item);
}
