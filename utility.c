#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * is_num - checks if the argument given is a number
 * Return: 0 if it is a number, -1 if is not
 */
int is_num(void)
{
	char *num = global.argument;

	if (*num == '-')
		num++;

	while (*num != '\0')
	{
		if (!isdigit(*num) && atoi(num) == 0)
			return (-1);
		num++;
	}
	return (0);
}

/**
 * set_mode - set the mode of the program to either stack
 * or queue
 * @stack: the stack
 * @line_number: the line current executed
 */
void set_mode(stack_s **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (global.opcode)
	{
		if (global.mode)
			free(global.mode);
		global.mode = strdup(global.opcode);
	}
}

/**
 * free_stack - frees the stack
 * @stack: stack
 */
void free_stack(stack_s *stack)
{
	stack_s *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
