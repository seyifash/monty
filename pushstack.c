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
	freestack(*head);
	exit(EXIT_FAILURE); }}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
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
 * mqueue - prints the top
 * @head: unused
 * @counter: unused
 * Return: no return
*/
void mqueue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	shared.tflag = 1;
}

/**
 * mstack - prints the top
 * @head: unused
 * @counter: unused
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
 * @head: unused
 * @counter: unsed
 * Return: no return
*/
void pallnode(stack_t **head, unsigned int counter)
{
	stack_t *curr;
	(void)counter;

	curr = *head;
	if (curr == NULL)
		return;
	while (curr)
	{
		printf("%d\n", h->n);
		curr = curr->next;
	}
}
