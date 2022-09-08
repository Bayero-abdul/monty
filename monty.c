#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

line_s global[] = {{NULL, {NULL, NULL}}};

/**
 * main - runs the monty program
 * @argc: number of cmdline arguments
 * @argv: pointer to the arguments
 * Return: Void
 */
int main(int argc, char *argv[])
{
	char line[20];
	stack_s *stack = NULL;
	unsigned int line_number = 1;
	ssize_t nread;
	void (*f)(stack_s **stack, unsigned int line_number);

	if (argc != 2)
		err_usage();

	global->stream = fopen(argv[1], "r");
	if (global->stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	    exit(EXIT_FAILURE);
	}

	while ((nread = get_line(line, global->stream)) != -1)
	{
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		if (line[0] != '\0')
		{
			parse(line);
			if (global->toks[0][0] == ' ')
			{
				line_number++;
				continue;
			}
			f = exec_op_func();
			if (f == NULL)
			{
				free_stack(stack);
				err_unknown(line_number);
			}
			f(&stack, line_number++);
		}
	}
	free_stack(stack);
	fclose(global->stream);
	exit(EXIT_SUCCESS);
}

/**
 * err_usage - usage error
 */
void err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
