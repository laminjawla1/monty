#include "monty.h"

/**
*get_opcode - reference a pointer to a function invoked by the user
*
*@identifier: Name of the function to be called
*
*Return: Pointer to a function
*/
void (*get_opcode(char *identifier))(stack_t **stack, unsigned int line_number)
{
	instruction_t routines[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL},
	};
	int i = 0;

	while (routines[i].opcode && (strcmp(routines[i].opcode, identifier) != 0))
		i++;
	return (routines[i].f);
}
