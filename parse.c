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
	global->toks[0] = strtok(line, " \t\n");
	if (global->toks[0] != NULL)
		global->toks[1] =  strtok(NULL, " \t\n");
}
