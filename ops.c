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

	if (*stack == NULL)
		err_less_than_2(line_number);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
