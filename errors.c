#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


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


/**
 * err_malloc - prints an error if malloc fails
 */
void err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
