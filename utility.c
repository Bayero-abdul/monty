#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * is_num - checks if the argument given is a number
 * Return: 0 if it is a number, -1 if is not
 */
int is_num(void)
{
	char *num = global->toks[1];

	if (atoi(num) == 0)
		return (-1);
	else
		return (0);
}


/**
 * get_line - gets a line in a file
 * @lineptr: pointer to line
 * @stream: pointer to a file
 * Return: line length if failed return -1
 */
int get_line(char *lineptr, FILE *stream)
{
	if (fgets(lineptr, 1024, stream) == NULL)
		return (-1);
	return (strlen(lineptr));
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
