#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "../include/concat.h"

//buffer storage to temporatily store buffers
char buff[BUFF_LENGTH];

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
        printf("\t--help :\tPrint the manual page.\n");
        printf("\n");
    }
    return 0;
};