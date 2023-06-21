#include "monty.h"

/**
 * fileError - erroe message to be printed if the file cannot be opened
 * @message: the message to be printed
 *
 */
void fileError(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
