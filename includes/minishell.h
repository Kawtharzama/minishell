
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
typedef struct s_envp {
    char **tmp_envp;  
    int counter;  
   
} t_envp;
typedef struct s_command{
    char *command;
    char **args;
    int args_index;
    struct s_command *next;
}t_command;

typedef enum e_types {
    WORD = 1,      
    PIPE = 2,    
    REDIR = 3,     
    HEREDOC = 4 
   
} t_types;

typedef struct s_lists{
    char *value;
    t_types type;
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
typedef struct s_all{
    struct s_envp *cp_envp;
    struct s_lists *head;
    struct s_command *cmd;
    char *new_input;
    char *variable;
}t_all;

void split_input(char *input, t_lists **head);
void print_list(t_lists *head);
t_lists *find_last_node(t_lists *head);
int add_node(t_lists **head, char *input);

void init_token(t_token *token);
int handle_quotes(char *input, int i, t_token *token, t_lists **head);
int closing_qoutes(char *input, int i);
int parameter_token(char *input, int i, t_token *token, t_lists **head);
int str(char *input, int i, t_token *token, t_lists **head);
void split_cmds(t_lists *head, t_command **cmd);
 void token_types(t_lists *node);
int	is_parameter(char c);
int is_cmd(char * value);
void parse_tokens(t_lists *head);
t_command	*find_last_cmd(t_command *cmd);
int add_cmd_node(t_command **cmd, char *str);
void print_cmds(t_command *cmd);
void remove_quotes(t_lists *head);
t_envp *copy_envp(char **envp, t_all *as);
char *find_var(char *input, int *i, char *var);
char *xpand_var(char *input, char* new_input, char *var);
int free_envp(t_envp *cp_envp);
int free_memory(t_all *as);
int init_envp(t_all *as);
t_all *init_structs();
int free_char(t_all *as);

#endif
