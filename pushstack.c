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
	free(shared.mcont);
	freestack(*head);
	exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(shared.file);
		free(shared.mcont);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(shared.arg);
	if (shared.tflag == 0)
		pushnode(head, n);
	else
		pushqueue(head, n);
}
/**
 * fqueue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void mqueue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	shared.tflag = 1;
}
/**
 * fstack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void mstack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	shared.tflag = 0;
}
/**
 * pallnode - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void pallnode(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
