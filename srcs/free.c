#include "../includes/minishell.h"

int free_envp(t_envp *cp_envp)
	{
		if(cp_envp && cp_envp->tmp_envp)
		{
			while(cp_envp->counter-- >= 0)
			{
				free(cp_envp->tmp_envp[cp_envp->counter]);
			}
			free(cp_envp->tmp_envp);
			free(cp_envp);
			return 1;
		}
		return 0;
	}
    int free_char(t_all *as)
    {
		if(!as->new_input || !as->variable)
			return 1;
       else{  free(as->new_input);
        
            free(as->variable);
        }
        return 0;
    }
	int free_nodes(t_lists **head)
    {
		t_lists *tmp;

		if (!head || !*head)
			return 1; 
	
		while (*head)
		{
			tmp = (*head)->next; 
			free(*head);         
			*head = tmp;  }       
		*head = NULL;
        return 0;
    }
	int free_cmds(t_command **cmd)
	{
		int i;
		t_command *tmp;
		if(!cmd ||!*cmd)
			return 1;
		while(*cmd)
		{
			tmp = (*cmd)->next;
			if ((*cmd)->args)
			{
				i = 0;
				while ((*cmd)->args[i])
					free((*cmd)->args[i++]); // Free each argument
				free((*cmd)->args);
				 // Free the args array
			}
			free((*cmd)->command); 
		
			free(*cmd);
		*cmd = tmp;
	}
return 0;

		
	}
	int free_memory(t_all *as)
	{
		if(as)
		{
			free_envp(as->cp_envp);
			free_char(as);
			free_nodes(&as->head);
			free_cmds(&as->cmd);

            
			free(as);
			return 1;
		}
		return 0;
	}