#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "../include/concat.h"
#include "../include/parse_token.h"

//buffer storage to temporatily store buffers
char buff[BUFF_LENGTH];
TOKEN_T flag_tokens = 0;

int main(int argc, char ** argv)
{
    signal(SIGINT, interrupt_handler);
    if (argc == 1)
    {
        stdin_concat();
    }
    else if (argc == 2 && !strncmp(argv[1], "--help", strlen("--help")))
    {
        printf("Usage: my_cat [OPTIONS]... [FILENAME]...\n");
        printf("Concatenate files and print to stdout.\n\n");
        printf("With no OPTION and FILE, read from stdin.\n");
        printf("\t--help\t:Print the manual page.\n");
        printf("\t-n\t:Print each line with line number\n");
        printf("\t-e\t:Show line end with a '$' sign\n");
        printf("\n");
    }
    else
    {
        int i = 1;
        while (i < argc && !strncmp(argv[i], "-", 1))
        {
            parse_token(&flag_tokens, argv[i]);
            i++;
        }
        if (i == argc)
        {
            fprintf(stderr, "missing FILENAME argument\n");
            exit(EXIT_SUCCESS);
        }
        for (; i < argc; i++)
        {
            parse_files(flag_tokens, argv[i]);
        }
    }
    return 0;
};