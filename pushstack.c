#include "monty.h"
/**
 * mpush - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void mpush(stack_t **head, unsigned int counter)
{
	int n, f = 0, flag = 0;

	if (shared.arg)
	{
	if (shared.arg[0] == '-')
	f++;
	for (; shared.arg[f] != '\0'; f++)
	{
	if (shared.arg[f] > '9' || shared.arg[f] < '0')
	flag = 1;
	}
	if (flag == 1)
	{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	fclose(shared.file);
	free(shared.content);
	free_stack(*head);
	exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(shared.file);
		free(shared.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(shared.arg);
	if (shared.tflag == 0)
		pushnode(head, n);
	else
		pushqueue(head, n);
}
