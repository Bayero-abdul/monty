#include <stdio.h>
#include <string.h>
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

	if (global.mode == NULL || strcmp(global.mode, "stack") == 0)
	{
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
			err_malloc();

		new_node->n = atoi(global.argument); /* assign integer to a variable */
		new_node->prev = NULL;
		new_node->next = NULL;

		if (*stack == NULL)
		{
			*stack = new_node;
			global.rear = new_node;
		}
		else
		{
			(*stack)->prev = new_node;
			new_node->next = *stack;
			*stack = new_node;
		}
	}
	else if (strcmp(global.mode, "queue") == 0)
		enqueue(stack);
}

/**
 * pop - removes the top element of the stack
 * @stack: stack
 * @line_number: line number current been executed
 */
void pop(stack_s **stack, unsigned int line_number)
{
	stack_s *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
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

	printf("%d\n", (*stack)->n);
}


/**
 * enqueue - Add element at the end of the stack
 * @stack: the stack
 * Return: void
 */
void enqueue(stack_s **stack)
{
	stack_s *new_node = malloc(sizeof(*new_node));

	if (new_node == NULL)
		err_malloc();

	new_node->n = atoi(global.argument);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		global.rear = new_node;
		return;
	}

	global.rear->next = new_node;
	new_node->prev = global.rear;
	global.rear = new_node;
}
