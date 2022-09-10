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

/**
* pchar_t - prints the char at the top of the stack
* @stack: stack
* @line_number: line number current been executed
*/
void pchar_t(stack_s **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
* pstr_t - prints the string starting at the top of the stack
* @stack: stack
* @line_number: line number current been executed
*/
void pstr_t(stack_s **stack, unsigned int line_number)
{
	int is_ascii = (*stack)->n >= 0 || (*stack)->n <= 127 ? 1 : 0;
	(void)line_number;

	while (*stack != NULL || is_ascii || (*stack)->n != 0)
		printf("%c", (*stack)->n);
	printf("\n");
}
