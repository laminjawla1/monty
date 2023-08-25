#include "monty.h"

/**
* stack - Sets the process id to '1'.
*	  Indicating that the datastructure
*	  should behave like a stack
*
*@head: Head of the doubly linked list
*@l: Current line in the script
*/
void stack(stack_t __attribute__((unused))**head, unsigned int l)
{
	(void)l;
	process.id = 1;
}
/**
* queue - Sets the process id to '0'.
*	  Indicating that the datastructure
*	  should behave like a queue
*
*@head: Head of the doubly linked list
*@l: Current line in the script
*/
void queue(stack_t __attribute__((unused))**head, unsigned int l)
{
	(void)l;
	process.id = 0;
}
