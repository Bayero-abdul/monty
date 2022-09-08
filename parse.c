#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * parse - parses the bytecode
 * @line: instruction
 * Return: void
 */
void parse(char line[])
{
	char *token = NULL;
	char *delimit = " \t\r\n\v\f";
	unsigned int i = 0;

	token = strtok(line, delimit);
	while (token != NULL && i < 2)
	{
		global->toks[i] = token;
		token = strtok(NULL, delimit);
		i++;
	}
}
