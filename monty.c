#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

line_s global = {NULL, NULL, NULL, NULL};

/**
 * main - runs the monty program
 * @argc: number of cmdline arguments
 * @argv: pointer to the arguments
 * Return: Void
 */
int main(int argc, char *argv[])
{
	ssize_t nread;
	char *line = global.line;
	size_t len = 0;
	stack_s *stack = NULL;
	unsigned int line_number = 1;
	void (*f)(stack_s **stack, unsigned int line_number);

	if (argc != 2)
		err_usage();

	global.stream = fopen(argv[1], "r");
	if (global.stream == NULL)
		err_open(argv[1]);

	while ((nread = getline(&line, &len, global.stream)) != -1)
	{
		if (*line != '\n')
		{
			global.opcode = strtok(line, " \t\n");
			if (!global.opcode || *global.opcode == '#')
			{
				line_number++;
				continue;
			}

			global.argument = strtok(NULL, " \t\n");
			f = exec_op_func();
			if (f == NULL)
				err_unknown(line_number);
			f(&stack, line_number);
		}
		line_number++;
	}

	free_stack(stack);
	free(line);
	fclose(global.stream);
	exit(EXIT_SUCCESS);
}

/**
 * err_open - prints error if file can't open
 * @filename: the file
 */
void err_open(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * err_usage - prints error if less or more arguments are given
 */
void err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * err_unknown - prints error when an unknown instruction is given
 * @line_number: line_number of the instruction
 */
void err_unknown(unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, global.opcode);
	exit(EXIT_FAILURE);
}
