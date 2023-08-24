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
		handle_error("can't pchar, stack empty", current_line);
	if ((*head)->n < ASCII_MIN || (*head)->n > ASCII_MAX)
		handle_error("can't pchar, value out of range", current_line);
	printf("%c\n", (*head)->n);
}
