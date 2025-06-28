#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/concat.h"
#include "../include/parse_token.h"

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

void parse_files(TOKEN_T tok, const char* fname)
{
    int fptr = open(fname, O_RDONLY);
    if (fptr == -1)
    {
        fprintf(stderr, "can't open file/directory: %s\n", fname);
        perror("Error");
        exit(EXIT_SUCCESS);
    }
    ssize_t bytes;
    while ((bytes = read(fptr, buff, BUFF_LENGTH)) > 0)
    {
        write(STDOUT_FILENO, buff, bytes);
    }
    if (bytes == -1)
    {
        perror("Can't perform read operation");
        exit(EXIT_FAILURE);
    }
    if (close(fptr) == -1)
    {
        perror("Oops! error closing file");
        exit(EXIT_FAILURE);
    }
};

void interrupt_handler(int sig)
{
    printf("\n");
    exit(EXIT_SUCCESS);
};