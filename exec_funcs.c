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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add_s},
		{"sub", sub_s},
		{"div", div_s},
		{"mul", mul_s},
		{"mod", mod_s},
		{"pchar", pchar_t},
		{"pstr", pstr_t},
		{"rotl", rotl_t},
		{"rotr", rotr_t},
		{"queue", set_mode},
		{"stack", set_mode},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, global.opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
