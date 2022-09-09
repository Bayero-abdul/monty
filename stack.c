#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: stack
 * @line_number: line number current been executed
 */
void push(stack_s **stack, unsigned int line_number)
{
	stack_s *new_node;
	(void)line_number;

	if (global.argument == NULL || is_num() == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		err_malloc();
	}

	new_node->n = atoi(global.argument); /* assign integer to a variable */
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
	}
}


/**
 * pall - print all elements in the stack
 * @stack: stack
 * @line_number: line number current been executed
 */
void pall(stack_s **stack, unsigned int line_number)
{
	stack_s *current;
	(void)line_number;

	if (*stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}


/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: line number beenn executed
 */
void pint(stack_s **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
