#include "monty.h"
/**
 * is_opcode- checks and compares the given opcode
 * @opcode: the opcode
 *
 * Return: returns a pointer to the corresponding function
 */
void (*is_opcode(char *opcode))(stack_t **, unsigned int)
{
	unsigned int i;

	instruction_t theopt[] = {
				{"push", mpush}, {"pall", pallnode},
				{"pint", pintnode}, {"pop", popnode},
				{"swap", swapnode}, {"add", addnode},
				{"nop", donop}, {"sub", subnode},
				{"div", divnode}, {"mul", mulnode},
				{"mod", modnode}, {"pchar", pcharnode},
				{"pstr", pstrnode}, {"rotl", rotlnode},
				{"rotr", rotrnode}, {"queue", mqueue},
				{"stack", mstack}, {NULL, NULL}
			};

	for (i = 0; theopt[i].opcode; i++)
	if (strcmp(theopt[i].opcode, opcode) == 0)
	return (theopt[i].f);

	return (NULL);
}
/**
 * handleops - checks the given opcode and returns its corresponding functions
 * @content: the content of the monty file
 * @stack: the head pointer of the stack
 * @counter: counts the number lines
 * @file: name of the monty file
 * Return: exit success on success
 */
int handleops(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	void (*opcode_func)(stack_t **, unsigned int);
	char *opt;

	opt = strtok(content, " \n\t");
	if (opt && opt[0] == '#')
	return (0);
	shared.arg = strtok(NULL, " \n\t");
	opcode_func = is_opcode(opt);
	if (opcode_func)
	{
	opcode_func(stack, counter);
	return (0);
	}
	else
	{
	fprintf(stderr, "L%u: unknown instruction %s\n", counter, opt);
	freestack(*stack);
	free(content);
	fclose(file);
	exit(EXIT_FAILURE);
	}

}
/**
* freestack - frees a doubly linked list
* @head: head of the stack
*/
void freestack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
