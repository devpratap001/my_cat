/*
this header controls function and datatye definitions for concate command functions and definitions.
*/

#ifndef CONCAT_H
#define CONCAT_H

//define length of I/O buffer
#define BUFF_LENGTH 10

//buffer storage to temporatily store buffers
extern char buff[BUFF_LENGTH];

//handle concatenation when default input is stdin
void stdin_concat(void);

// Ctrl + C(interrupt) or Ctrl + D (EOF) signal handler
void interrupt_handler(int);


#endif