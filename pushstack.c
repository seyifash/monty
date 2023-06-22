#include "monty.h"
/**
* mqueue - sets the stack mode to queue (FIFO)
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
* mstack - sets the stack mode to stack (LIFO)
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
* @head: stack head
* @counter: unused
* Return: no return
*/
void pallnode(stack_t **head, unsigned int counter)
{
stack_t *curr;
(void)counter;
curr = *head;
while (curr != NULL)
{
printf("%d\n", curr->n);
curr = curr->next;
}
}
/**
* pushnode - pushes a node to the top of the stack in a linked list
* @head: the pointer to the hea node
* @value: the dataa to be pushed onto the stack
* Return: no return
*/
void pushnode(stack_t **head, int value)
{
stack_t *new_node, *curr;
curr = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (curr)
curr->prev = new_node;
new_node->n = value;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}
