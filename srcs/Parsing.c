#include "../includes/minishell.h"
void print_cmds(t_command *cmd) {
    while (cmd) {
        printf("Command: %s\n", cmd->command);
        if (cmd->args_index > 0) {
            printf("Arguments: ");
            for (int i = 0; i < cmd->args_index; i++) {
                printf("%s ", cmd->args[i]);
            }
            printf("\n");
            
        }
        cmd = cmd->next;
    }}

t_command	*find_last_cmd(t_command *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next != NULL)
	{
		cmd = cmd->next;
	}
	return (cmd);
}
int add_cmd_node(t_command **cmd, char *str){   
    
    t_command *current_cmd;
    t_command *last_cmd;
     if(!str)
        return -1;
    current_cmd = malloc(sizeof(t_command));
    if(!current_cmd){return -1;} 
    current_cmd->command = str; 
    current_cmd->args = malloc(sizeof(char*) * 10);  // Initialize args array with some initial size (e.g., 10)
    current_cmd->args_index = 0;  // No arguments initially
   current_cmd->next = NULL;

   if(*cmd == NULL)
   {
    *cmd = current_cmd;
   }
   else{
         last_cmd = find_last_cmd(*cmd);
        last_cmd ->next = current_cmd;
    }
    return 0;
}
// init cmds_node if first word | re app herdo ->cmds
//args any thing followed  
void split_cmds(t_lists *head, t_command **cmd) 
{   
   *cmd = NULL;
    int i =0;
    t_command *last_cmd = NULL; 
    while(head){
    if (!(head->prev) || (head->prev && (head->prev->type == PIPE)))
    {        
               
        if (add_cmd_node(cmd, head->value) == -1)
                exit(1);
        // last_cmd = find_last_cmd(*cmd);  
     
         
          }
    else if ((head->type == REDIR) || (head->type) == HEREDOC) {
             
         if (add_cmd_node(cmd, head->value) == -1)
            exit(1); //free
        // last_cmd = find_last_cmd(*cmd);  
                 
                     
                      
         }
    else if (head->type == PIPE)
         {        
               
           if (add_cmd_node(cmd, head->value) == -1)
                exit(1); //free
            // last_cmd = find_last_cmd(*cmd);  
     
         
          }
        
    else{
         
        last_cmd = find_last_cmd(*cmd); 
        if (last_cmd) 
        {
            last_cmd->args[last_cmd->args_index] = ft_strdup(head->value); // how to free
            last_cmd->args_index++;
        }

     
          }         
    if (i == -1)
    {
        exit(1);
    }
    head = head->next;
    }
    
    // print_cmds(*cmd);
    
}

void token_types(t_lists *head) 
{
    while(head)  {
        if ((strcmp(head->value, ">") == 0) || (strcmp(head->value, "<") == 0) || (strcmp(head->value, ">>") == 0)) {
            head->type = REDIR;
        }
         else if (strcmp(head->value, "<<") == 0) {
            head->type = HEREDOC;
        }
        else if (strcmp(head->value, "|") == 0) {
            head->type = PIPE;
        }
        else {
            head->type = WORD;       

        }
        head = head->next;
   
    }
      
}
