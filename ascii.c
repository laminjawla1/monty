#include "monty.h"

/**
* pchar - Prints the char at the top of the stack, followed by a newline
*
*@head: Head of the stack
*@current_line: Current line
*/
void pchar(stack_t **head, unsigned int current_line)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < ASCII_MIN || (*head)->n > ASCII_MAX)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", current_line);
		shutdown();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
