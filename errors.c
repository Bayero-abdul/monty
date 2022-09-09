#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * err_malloc - prints an error if malloc fails
 */
void err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}


/**
 * err_less_than_2 - prints an error if stack elements
 * is less than 2
 * @line_number: line number in the file been executed
 */
void err_less_than_2(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
