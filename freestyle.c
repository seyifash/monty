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
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (lineread != -1)
    {
        counter++;
        lineread = getline(&filecontent, &n, file);

        char *opcode = strtok(filecontent, " \n\t");
        if (opcode && opcode[0] != '#')
        {
            if (!is_opcode_valid(opcode))
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", counter, opcode);
                fclose(file);
                free(filecontent);
                exit(EXIT_FAILURE);
            }
            instruction_t *instruction = get_instruction_function(opcode);
            if (instruction)
            {
                instruction->f(&stack, counter);
            }
            else
            {
                fprintf(stderr, "L%u: instruction function not found for opcode %s\n", counter, opcode);
                fclose(file);
                free(filecontent);
                exit(EXIT_FAILURE);
            }
        }
        free(filecontent);
    }
    fclose(file);
    return 0;
}
