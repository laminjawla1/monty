#include "monty.h"

/**
* create_node - Creates a new node
*
*@n: Value for field of the node
*
*Return: The newly created node
*/
stack_t *create_node(const int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
* add_dnodeint - Insert a new node at the beginning of the list
*
*@head: Head of the list
*@n: Value to be stored in field of the created node
*
*Return: A pointer to the head of the list
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node = create_node(n);

	if (!node)
		return (NULL);
	if (!*head)
	{
		node->next = *head;
		*head = node;
	}
	else
	{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
	return (*head);
}
/**
* add_dnodeint_end - Adds a new node at the end of the list
*
*@head: A pointer to the list
*@n: A value for the field of the newly created  node
*
*Return: A pointer to the list
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *node = create_node(n);

	if (!node)
		return (NULL);
	if (!*head)
	{
		node->next = *head;
		*head = node;
		return (*head);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	return (*head);
}
