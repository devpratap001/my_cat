//this contains all the functions and declaration regarding IO redirection using '<' and '>'

#ifndef IO_REDIRECT_H
#define IO_REDIRECT_H

//symbols for IO redirection CLI input
extern char out[2];
extern char in[2];

//redirect stdout or stdin to some file
void io_redirect(const char* flag, const char* fname);

//original file descriptors for STDIN and STDOUT
extern int original_stdin;
extern int original_stdout;

//restore original description of STDIN and STDOUT
void restore_descriptors(void);

#endif