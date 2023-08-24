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
		handle_error("can't add, stack too short", current_line);
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
		handle_error("can't sub, stack too short", current_line);
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
		handle_error("can't div, stack too short", current_line);
	if ((*head)->n == 0)
		handle_error("division by zero", current_line);
	(*head)->next->n /= (*head)->n;
	pop(head, current_line);
}
/**
* mul - Multiplies the second top element of the stack
*	by the top element of the stack
*
*@head: Head of the stack
*@current_line: Current line
*/
void mul(stack_t **head, unsigned int current_line)
{
	if (dlist_len(*head) < 2)
		handle_error("can't mul, stack too short", current_line);
	(*head)->next->n *= (*head)->n;
	pop(head, current_line);
}
/**
* mod - Mod the second top element of the stack
*	by the top element of the stack
*
*@head: Head of the stack
*@current_line: Current line
*/
void mod(stack_t **head, unsigned int current_line)
{
	if (dlist_len(*head) < 2)
		handle_error("can't mod, stack too short", current_line);
	if ((*head)->n == 0)
		handle_error("division by zero", current_line);
	(*head)->next->n %= (*head)->n;
	pop(head, current_line);
}
