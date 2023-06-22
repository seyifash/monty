#include "monty.h"
#include <stdio.h>
/**
* pallnode - Prints all the values on the stack
* @stack: Double pointer to the head of the stack
*
* Description:
* This function prints all the values stored in the stack,
* starting from the top of the stack.
*/
void pallnode(stack_t **stack)
{
stack_t *current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
