
#ifndef MINISHELL_H
#define MINISHELL_H
//include library
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "../libft/libft.h"

//write functions

typedef enum e_types{
 CMD,
 Operator,
 Qoute,
 Invalid,
 arg,// add it to type function 
 file // add it to type seperate type function from toknization
}types;
typedef struct s_lists{
    char *value;
    types type;
    struct s_lists *prev;
   struct s_lists *next;
}t_lists;
typedef struct s_token{
    char *value;
    int start;
    int end;
   // size_t *counter;
    //struct s_lists *next;
} t_token;


void print_list(t_lists *head);
t_lists *find_last_node(t_lists *head);
void add_node(t_lists **head, char *input);
void init_token(t_token *token);
int handle_d_quotes(char *input, int i, t_token *token, t_lists **head);
int handle_s_quotes(char *input, int i, t_token *token, t_lists **head);
int is_parameter(char *input, int i, t_token *token, t_lists **head);
int str(char *input, int i, t_token *token, t_lists **head);
void split_command(char *input);
void handle_sigint(int sig);
void setup_signals();
void token_type(t_lists *node);

int	parameter_char(char c);
int	is_space(char c);


#endif
