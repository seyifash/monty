#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct shared_v - variables -args, file, line content
 * @arg: value
 * @fname: pointer to monty file
 * @mcont: line content
 * @tflag: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct shared_v
{
	char *arg;
	FILE *file;
	char *mcont;
	int  tflag;
}  shared_vv;
extern shared_vv shared;
int handleops(char *content, stack_t **stack, unsigned int num, FILE *file);
void swapnode(stack_t **head, unsigned int line_num);
void popnode(stack_t **head, unsigned int line_num);
void pintnode(stack_t **head, unsigned int line_num);
void pushnode(stack_t **head, int value);
void pushqueue(stack_t **head, int value);
void (*is_opcode(char *opcode))(stack_t **, unsigned int);
void rotrnode(stack_t **head, unsigned int line_num);
void rotlnode(stack_t **head, unsigned int line_num);
void pstrnode(stack_t **head, unsigned int line_num);
void pcharnode(stack_t **head, unsigned int line_num);
void modnode(stack_t **head, unsigned int line_num);
void mulnode(stack_t **head, unsigned int line_num);
void fileError(char *filename);
void freestack(stack_t *head);
void divnode(stack_t **head, unsigned int line_num);
void subnode(stack_t **head, unsigned int line_num);
void donop(stack_t **head, unsigned int line_num);
void addnode(stack_t **head, unsigned int line_num);
void mqueue(stack_t **head, unsigned int counter);
void mstack(stack_t **head, unsigned int counter);
void mpush(stack_t **head, unsigned int counter);
void pallnode(stack_t **head, unsigned int counter);
#endif
