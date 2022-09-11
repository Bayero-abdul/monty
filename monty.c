#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

global_s global = {NULL, NULL, NULL, NULL, NULL};

/**
 * main - runs the monty program
 * @argc: number of cmdline arguments
 * @argv: pointer to the arguments
 * Return: Void
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	ssize_t nread;
	size_t len = 0;
	stack_s *stack = NULL;
	unsigned int line_number = 1;
	void (*f)(stack_s **stack, unsigned int line_number);

	if (argc != 2)
		err_usage();

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		err_open(argv[1]);

	while ((nread = getline(&global.line, &len, stream)) != -1)
	{
		if (*global.line == '\n')
		{
			line_number++;
			continue;
		}

		global.opcode = strtok(global.line, " \t\n");
		if (!global.opcode || *global.opcode == '#' || !strcmp(global.opcode, "nop"))
		{
			line_number++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		f = exec_op_func();
		if (f == NULL)
			err_unknown(line_number);
		f(&stack, line_number);
		line_number++;
	}
	free_stack(stack);
	free(global.line);
	free(global.mode);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
