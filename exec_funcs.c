#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"


/**
 * exec_op_func - executes opcode function
 * Return: pointer to opcode function if found else
 * return NULL
 */
void(*exec_op_func(void))(stack_s * *stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, global->toks[0]) == 0)
			return (ops[i].f);
		i++;
	}
	return (ops[i].f);
}
