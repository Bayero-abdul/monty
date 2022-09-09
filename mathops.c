#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
* add_s - adds the top two elements of the stack
* @stack: stack
* @line_number: line number current been executed
*/
void add_s(stack_s **stack, unsigned int line_number)
{
	stack_s *temp;
	int add;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	add = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = add;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * sub_s - subtracts the top two elements of the stack
 * @stack: stack
 * @line_number: line number current been executed
 */
void sub_s(stack_s **stack, unsigned int line_number)
{
	stack_s *temp;
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * div_s - divides the second top element of the stack by the
 * top element of the stack
 *
 * @stack: stack
 * @line_number: line number current been executed
 */
void div_s(stack_s **stack, unsigned int line_number)
{
	stack_s *temp;
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * mul_s - multiplies the second top element of the stack with the
 * top element of the stack
 *
 * @stack: stack
 * @line_number: line number current been executed
 */
void mul_s(stack_s **stack, unsigned int line_number)
{
	stack_s *temp;
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = mul;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * mod_s - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 *
 * @stack: stack
 * @line_number: line number current been executed
 */
void mod_s(stack_s **stack, unsigned int line_number)
{
	stack_s *temp;
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = mod;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
