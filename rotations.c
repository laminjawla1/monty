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
/**
*rotr - Rotates the stack to the bottom.
*
*@head: Head of the linked list
*@l: Current_line
*/
void rotr(stack_t **head, unsigned int __attribute__((unused))l)
{
	int n;
	stack_t *tmp = *head;

	if (!*head || !(*head)->next)
		return;
	while (tmp->next->next)
		tmp = tmp->next;
	n = tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
	add_dnodeint(head, n);
}
