#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/concat.h"
#include "../include/parse_token.h"

TOKEN_T* parse_token(TOKEN_T* tok, char* path)
{
    if (strlen(path) != 2)
    {
        fprintf(stderr, "invalid flag argument '%s'\n", path);
        printf("please use '--help' to see list of possible flags\n");
        exit(EXIT_SUCCESS);
    }
    switch (*(path + 1))
    {
    case 'n':
        *tok |= NUMBER;
        break;
    case 'e':
        *tok |= ENDS;
        break;
    
    default:
        fprintf(stderr, "invalid flag argument '%s'\n", path);
        printf("please use '--help' to see list of possible flags\n");
        exit(EXIT_SUCCESS);
        break;
    }
    return tok;
};