#include "monty.h"
#include <stdio.h>
/**
 * main - monty code inteprter that executes the code
 * @argc: number of arguments
 * @argv: the monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *filecontent = NULL;
	FILE *file;
	size_t n = 0;
	stack_t *stack = NULL;
	ssize_t lineread = 1;
	unsigned int counter = 0;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	shared.file = file;
	if (!file)
	{
	fileError(argv[1]);
	}
	while (lineread > 0)
	{
	counter++;
	lineread = getline(&filecontent, &n, file);
	shared.mcont = filecontent;
	handleops(filecontent, &stack, counter, file);
	free(filecontent);
	}
	freestack(stack);
	fclose(file);
	return (0);
}
