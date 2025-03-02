
#ifndef MINISHELL_H
#define MINISHELL_H
//include library
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <string.h>

//write functions

int main(void);
typedef struct s_token{
    char *value;
    int start;
    int end;
    struct s_token *next;
} t_token;



#endif
