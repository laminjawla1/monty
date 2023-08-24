#include <stdio.h>
#include "monty.h"

/*The current process public variables*/
process_t process;

/**
* main - Entry point to the monty program
*
*@argc: Argument count
*@argv: Argument vector
*
*Return: 0 on success
*/
int main(int argc, char *argv[])
{
	size_t n = 0;
	FILE *script;
	void (*f)(stack_t **stack, unsigned int line_number);
	char *command = NULL, *sep = " \r\t\n", *cmd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	script = fopen(argv[1], "r");
	if (!script)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	__init__(script);
	while (getline(&cmd, &n, script) != -1)
	{
		command = strtok(cmd, sep);
		if (command && *command != '#')
		{
			f = get_opcode(command);
			if (!f)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
					process.line_count, command);
				free(cmd);
				shutdown();
				exit(EXIT_FAILURE);
			}
			process.arg = strtok(NULL, sep);
			f(&process.head, process.line_count);
		}
		process.line_count++;
	}
	free(cmd);
	shutdown();
	return (0);
}
/**
* __init__ - Initializes the current process
*
*@script: The program to be executed
*/
void __init__(FILE *script)
{
	process.id = 1;
	process.script = script;
	process.line_count = 1;
	process.head = NULL;
	process.arg = NULL;
}
/**
* shutdown - Deallocates the current process
*/
void shutdown(void)
{
	free_dlist(process.head);
	fclose(process.script);
}
