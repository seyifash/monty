#include "monty.h"

/**
 * handleops - checks the given opcode and returns its corresponding functions
 * @content: the content of the monty file
 * @stack: the head pointer of the stack
 * @counter: counts the number lines
 * @file: the name of the monty file
 * Return: no return
 */
int handleops(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t theopt[] = {
				{"push", mpush}, {"pall", mpall},
				{"pint", pintnode},{"pop", popnode},
				{"swap", swapnode}, {"add", addnode},
				{"nop", donop}, {"sub", subnode},
				{"div", divnode}, {"mul", mulnode},
				{"mod", modnode}, {"pchar", pcharnode},
				{"pstr", pstrnode}, {"rotl", rotlnode},
				{"rotr", rotrnode}, {"queue", pushqueue},
				{"stack", mstack}, {NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	opt = strtok(content, " \n\t");
	if (opt && opt[0] == '#')
		return (0);
	shared.arg = strtok(NULL, " \n\t");
	while (theopt[i].opcode && opt)
	{
		if (strcmp(opt, theopt[i].opcode) == 0)
		{
		theopt[i].f(stack, counter);
		return (0);
		}
		i++;
	}
	if (op && theopt[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opt);
		fclose(file);
		free(content);
		free_st(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
