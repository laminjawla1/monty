#ifndef MONTY_H
#define MONTY_H

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*Global Macros*/
#define ASCII_MIN 0
#define ASCII_MAX 127

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct process_public_vars - Defines the global variables
*
*@id: ID of the current process
*@script: It contains the commands to be run
*@line_count: Number of lines in the provide script
*@head: A pointer to the head of the stack
*@arg: Argument to the invoked function
*
*Description: Global variables for the current process
*/
typedef struct process_public_vars
{
	int id;
	FILE *script;
	size_t line_count;
	char *arg;
	stack_t *head;
} process_t;

/*Global declaration*/
extern process_t process;

/*Function types*/
void (*get_opcode(char *identifier))(stack_t **stack, unsigned int line_num);
void __init__(FILE *script);
void shutdown(void);

/*Utilities*/
void free_dlist(stack_t *head);
size_t dlist_len(stack_t *head);
void nop(stack_t __attribute__((unused))**h, unsigned int l);
void handle_error(const char *message, unsigned int current_line);

/*Linked list*/
stack_t *create_node(const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/*Opcodes routine prototypes*/
void push(stack_t **head, unsigned int current_line);
void pall(stack_t **head, unsigned int __attribute__((unused))current_line);
void pint(stack_t **head, unsigned int current_line);
void pop(stack_t **head, unsigned int current_line);
void swap(stack_t **head, unsigned int current_line);
void rotl(stack_t **head, unsigned int current_line);

/*Ascii*/
void pchar(stack_t **head, unsigned int current_line);
void pstr(stack_t **head, unsigned int __attribute__((unused))current_line);

/*Math*/
void add(stack_t **head, unsigned int current_line);
void sub(stack_t **head, unsigned int current_line);
void _div(stack_t **head, unsigned int current_line);
void mul(stack_t **head, unsigned int current_line);
void mod(stack_t **head, unsigned int current_line);
#endif
