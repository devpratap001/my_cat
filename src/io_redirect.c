#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/io_redirect.h"

void io_redirect(const char* flag, const char* fname)
{
    int newf = open(fname, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (newf == -1)
    {
        perror("can't open file/directory");
        exit(EXIT_FAILURE);
    }
    if (!strcmp(flag, in))
    {
        original_stdin = dup(STDIN_FILENO);
        dup2(newf, STDIN_FILENO);
    }
    else if (!strcmp(flag, out))
    {
        original_stdout = dup(STDOUT_FILENO);
        dup2(newf, STDOUT_FILENO);
    }
    close(newf);
};

void restore_descriptors(void)
{
    if (!isatty(STDIN_FILENO))
    {
        dup2(original_stdin, STDIN_FILENO);
    }
    if (!isatty(STDOUT_FILENO))
    {
        dup2(original_stdout, STDOUT_FILENO);
    }
}