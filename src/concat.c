#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/concat.h"

void stdin_concat(void)
{
    while (1)
    {
        char *ptr;
        ptr = fgets(buff, BUFF_LENGTH, stdin);
        if (ptr == NULL)
        {
            if (feof(stdin))
            {
                exit(EXIT_SUCCESS);
            }
            if (ferror(stdin))
            {
                perror("can't read from stdin");
                exit(EXIT_FAILURE);
            }
        }
        if (!(fputs(buff, stdout) > 0))
        {
            perror("can't write to stdout");
            exit(EXIT_FAILURE);
        }
    }
};

void interrupt_handler(int sig)
{
    printf("\n");
    exit(EXIT_SUCCESS);
};