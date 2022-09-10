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
	stack_s *current;
	int is_ascii;
	(void)line_number;

	current = *stack;
	while (current && current->n != 0)
	{
		is_ascii = current->n >= 0 && current->n <= 127;
		if (is_ascii == 1)
			putchar(current->n);
		else
			break;
		current = current->next;
	}
	printf("\n");
}

/**
* rotl_t - rotates the stack to the top; the top element of the stack becomes
* the last one, and the second element of the stack becomes the first one
*
* @stack: stack
* @line_number: line number current been executed
*/
void rotl_t(stack_s **stack, unsigned int line_number)
{
	stack_s *top, *last;
	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		return;

	top = *stack;

	*stack = top->next;
	top->next->prev = NULL;

	last = *stack;
	while (last->next)
		last = last->next;

	last->next = top;
	top->next = NULL;
	top->prev = last;
}

/**
* rotr_t - rotates the stack to the bottom; the last element of the stack
* becomes the top element of the stack
*
* @stack: stack
* @line_number: line number current been executed
*/
void rotr_t(stack_s **stack, unsigned int line_number)
{
	stack_s *top, *last;
	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		return;

	last = *stack;
	while (last->next)
		last = last->next;

	top = *stack;

	last->prev->next = NULL;
	top->prev = last;
	last->next = top;
	last->prev = NULL;
	*stack = last;
}
