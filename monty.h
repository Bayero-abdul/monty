#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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
} stack_s;

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
	void (*f)(stack_s **stack, unsigned int line_number);
} instruction_t;


/**
 * struct line_s - file stream and tokens
 * @stream: the FILE stream
 * @toks: the tokens
 *
 * Description: file stream and tokens for opcode
 */
typedef struct global_s
{
	char *mode;
	char *opcode;
	char *argument;
	char *line;
	stack_s *rear;
} global_s;

/* global varaible */
extern global_s global;

/* stack functions */
void push(stack_s **stack, unsigned int line_number);
void pop(stack_s **stack, unsigned int line_number);
void pall(stack_s **stack, unsigned int line_number);
void pint(stack_s **stack, unsigned int line_number);
void enqueue(stack_s **stack);

/* ops.c */
void swap(stack_s **stack, unsigned int line_number);

/* mathops.c */
void add_s(stack_s **stack, unsigned int line_number);
void sub_s(stack_s **stack, unsigned int line_number);
void div_s(stack_s **stack, unsigned int line_number);
void mul_s(stack_s **stack, unsigned int line_number);
void mod_s(stack_s **stack, unsigned int line_number);
void pchar_t(stack_s **stack, unsigned int line_number);
void pstr_t(stack_s **stack, unsigned int line_number);
void rotl_t(stack_s **stack, unsigned int line_number);
void rotr_t(stack_s **stack, unsigned int line_number);

/* exec_funcs */
void (*exec_op_func(void))(stack_s **stack, unsigned int line_number);

/* error functions */
void err_malloc(void);
void err_open(char *filename);
void err_usage(void);
void err_unknown(unsigned int line_number);

/* utility functions */
int is_num(void);
void free_stack(stack_s *stack);
void set_mode(stack_s **stack, unsigned int line_number);

#endif /* MONTY_H */
