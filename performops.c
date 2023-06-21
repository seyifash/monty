#include "monty.h"
/**
 * addnode - adds the top two elements of the stack.
 * @head: the head ointer to the top of the stack
 * @line_num: the linenumber that contains the byte code
 */
void addnode(stacK_t **head, unsigned int line_num)
{
	stack_t *temp;
	int sum = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
	fclose(shared.fname);
	free(shares.mcont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	sum = (*head)->n + (*head)->next->n;
	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
	(*head)->n = sum;
}
/**
  *donop- nothing
  *@head: stack head
  *@line_num: line_number
  *Return: no return
 */
void donop(stack_t **head, unsigned int line_num)
{
	(void) line_num;
	(void) head;
}
#include "monty.h"
/**
  *subnode- sustration
  *@head: stack head
  *@line_num: line_number
  *Return: no return
 */
void subnode(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int result = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
	fclose(shared.fname);
	free(shared.mcont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	temp = *head;
	result = (*head)->next->n - (*head)->n;
	(*head)->next->n = result;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
/**
 *divnode - divides the top two elements of the stack.
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
void divnode(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int result = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
	fclose(shared.fname);
	free(shared.mcont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", line_num);
	fclose(shared.fname);
	free(shared.mcont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	temp = *head;
	result = (*head)->next->n / (*head)->n;
	(*head)->next->n = result;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
/**
 * mulnode - divides the top two elements of the stack.
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
void mulnode(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int result = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
	fclose(shared.fname);
	free(shared.mcont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	temp = *head;
	result = (*head)->next->n * (*head)->n;
	(*head)->next->n = result;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

