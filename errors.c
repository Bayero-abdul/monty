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
