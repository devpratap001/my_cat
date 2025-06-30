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

void parse_files(TOKEN_T tok, const char *fname)
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
        if (!tok)
        {
            write(STDOUT_FILENO, buff, bytes);
        }
        else
        {
            print_file(tok, buff, bytes);
        }
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

void print_file(TOKEN_T tok, char buff[BUFF_LENGTH], size_t bytes)
{
    static int line_no = 1;
    static char last_char = '\n';
    static int last_line_blank = 0;
    for (size_t i = 0; i < bytes; i++)
    {
        if (last_char == '\n')
        {
            if (last_line_blank && buff[i] == '\n' && (tok & SQUEEZE_BLANK))
            {
                continue;
            }
            if (tok & NUMBER || (buff[i] != '\n' && (  tok & NUMBER_NON_BLANK )))
            {
                char temp[LINE_NO_SIZE];
                size_t len = snprintf(temp, sizeof(temp), "%6d\t", line_no++);
                if (len > BUFF_LENGTH)
                {
                    len = BUFF_LENGTH;
                    temp[len -1] = '\0';
                }
                flush_out_buff(&out_buff_index, len, 1);
                memcpy(out_buff + out_buff_index, temp, len);
                out_buff_index += len;
            }
        }
        if (buff[i] == '\n')
        {
            if (tok & ENDS)
            {
                flush_out_buff(&out_buff_index, 1, 0);
                out_buff[out_buff_index++] = '$';
            }
            if (last_char == '\n')
                last_line_blank = 1;
            else
                last_line_blank = 0;
        }
        last_char = buff[i];
        flush_out_buff(&out_buff_index, 1, 0);
        out_buff[out_buff_index++] = buff[i];
    }
};

void flush_out_buff(size_t *out_index, size_t len, FORCE_FLUSH is_forced)
{
    if (is_forced)
    {
        write(STDOUT_FILENO, out_buff, *out_index);
        *out_index = 0;
        return;
    }
    if (*out_index + len > BUFF_LENGTH)
    {
        write(STDOUT_FILENO, out_buff, BUFF_LENGTH);
        *out_index = 0;
    }
}

void interrupt_handler(int sig)
{
    printf("\n");
    exit(EXIT_SUCCESS);
};