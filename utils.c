#include "monty.h"

/**
* free_dlist - Frees the dynamically allocated linked list
*
*@head: Pointer to the head of linked list
*/
void free_dlist(stack_t *head)
{
	stack_t *tmp = head;

	while (tmp)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
/**
* dlist_len - Gets the len of the dlist
*
*@head: Head of the linked list
*
*Return: len(stack)
*/
size_t dlist_len(stack_t *head)
{
	size_t len = 0;

	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);	
}
