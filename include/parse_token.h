// this header contains datatypes and function definitions to parse user command line input tokens

#ifndef PARSE_TOKENS_H
#define PARSE_TOKENS_H

//structure to store list of possible tokens
#define FLAGS_LEN 2

//bit fields for flags list
//putting line no. after each line
#define NUMBER (1 << 0)
//putting a $ sign after every line
#define ENDS (1 << 1)

//token value for each flag and parse token from command line
typedef signed char TOKEN_T;
TOKEN_T* parse_token(TOKEN_T*, char*);
extern TOKEN_T flag_tokens;

#endif