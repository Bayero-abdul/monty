#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * err_malloc - prints an error if malloc fails
 * @stack: stack
 */
void err_malloc(stack_s *stack)
{
	free_stack(stack);
	fclose(global->stream);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}


/**
 * err_unknown - prints an error if argument is not an integer
 * @line_number: line been executed
 */
void err_unknown(unsigned int line_number)
{
	char *opcode =  global->toks[0];

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	fclose(global->stream);
	exit(EXIT_FAILURE);
}
