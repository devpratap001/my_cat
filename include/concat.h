/*
this header controls function and datatye definitions for concate command functions and definitions.
*/

#ifndef CONCAT_H
#define CONCAT_H

#include "parse_token.h"

//define length of I/O buffer
#define BUFF_LENGTH 20

//buffer storage to temporatily store buffers
extern char buff[BUFF_LENGTH];

//output buffer to store flag modefied buffer data
extern char out_buff[BUFF_LENGTH];
extern size_t out_buff_index;

//force flush out buffer even if its not full
typedef int FORCE_FLUSH;
#define FORCE_T 1

//function to flush output buffer
void flush_out_buff(size_t *out_index, size_t len, FORCE_FLUSH);

//max length to store line no character for -n flag
#define LINE_NO_SIZE 16     //24, for 64 bit implementation 

//handle concatenation when default input is stdin
void stdin_concat(void);

// Ctrl + C(interrupt) or Ctrl + D (EOF) signal handler
void interrupt_handler(int);

//Parse filenames and print the content on the screen
void parse_files(TOKEN_T, const char*);

//write file content to stdout and modify according to flags
void print_file(TOKEN_T, char[BUFF_LENGTH], size_t);

#endif