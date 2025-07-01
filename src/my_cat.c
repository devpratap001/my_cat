#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "../include/concat.h"
#include "../include/parse_token.h"

//buffer storage to temporatily store buffers
char buff[BUFF_LENGTH];

//output buffer to store flag modefied buffer data
char out_buff[BUFF_LENGTH];
size_t out_buff_index = 0;

//flag storage variable
TOKEN_T flag_tokens = 0;

int main(int argc, char ** argv)
{
    signal(SIGINT, interrupt_handler);
    if (argc == 1)
    {
        stdin_concat(flag_tokens);
    }
    else if (argc == 2 && !strncmp(argv[1], "--help", strlen("--help")))
    {
        printf("Usage: my_cat [OPTIONS]... [FILENAME]...\n");
        printf("Concatenate files and print to stdout.\n\n");
        printf("With no OPTION and FILE, read from stdin.\n");
        printf("\t--help\t:Print the manual page.\n");
        printf("\t-n\t:Print each line with line number\n");
        printf("\t-e\t:Show line end with a '$' sign\n");
        printf("\t-b\t:Print line number for non-blank lines\n");
        printf("\t-s\t:Suppress repeated empty output lines\n");
        printf("\n");
    }
    else
    {
        int flag_count = 0;
        for (int i = 1; i < argc; i++)
        {
            if ( argv[i][0] == '-' )
            {
                parse_token(&flag_tokens, argv[i]);
                flag_count ++;
            }
            else if ( argv[i][0] == '<' || argv[i][0] == '>' )
            {
                flag_count++;
            }
        }
        if (flag_count == argc -1)
        {
            stdin_concat(flag_tokens);
            flush_out_buff(&out_buff_index, 0, FORCE_T);
            return 0;
        }

        for (size_t i = 1; i < argc; i++)
        {
            if (argv[i][0] != '-' && argv[i][0] != '<' && argv[i][0] != '>')
            {
                parse_files(flag_tokens, argv[i]);
            }
        }
        flush_out_buff(&out_buff_index, 0, FORCE_T);
    }
    return 0;
};