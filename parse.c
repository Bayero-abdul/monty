#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * parse - parses the bytecode
 * @line: instruction
 * Return: void
 */
void parse(char *line)
{
	char *token = NULL;
	unsigned int i = 0;

	token = strtok(line, " ");
	while (token != NULL && i < 2)
	{
		global->toks[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
}
