#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
* swap - swaps the top two elements of the stack
* @stack: stack
* @line_number: line number current been executed
*/
void swap(stack_s **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
