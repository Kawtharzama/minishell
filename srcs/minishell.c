#include "../includes/minishell.h"

int		si = 0;

	t_envp *copy_envp(char **envp, t_all *as)
	{
		
		int count ;
		int r ;
		r = 0;
		
		count = 0 ;
		while(envp[count])
			count++;
		as->cp_envp->tmp_envp = malloc(sizeof(char*) * (count+1)); //free
		if (!as->cp_envp->tmp_envp)
        	return (NULL);
		while(envp[r])
		{
			as->cp_envp->tmp_envp[r] = ft_strdup(envp[r]);
        	if (!as->cp_envp->tmp_envp[r])
            return (NULL);
			
			r++;
		}
		as->cp_envp->tmp_envp[r] = NULL;
		as->cp_envp->counter = r;
		return as->cp_envp;

	}
	void print_envp(t_envp *cp_envp)
	{
		int r = 0 ;
		while(cp_envp->tmp_envp[r])
		{
			printf("%s\n", cp_envp->tmp_envp[r]);
			r++;
		}

	}
	char *find_var(char *input, int *i, char *var)
	{
		int j=0;
		var = malloc(256 * sizeof(char));  // Example size
		char *value;
    
		if (var == NULL) {
			return NULL;
		}
		(*i)++;
		if(input[*i] && (ft_isalpha(input[*i]) || input[*i] == '_')){

			while(input[*i] && (input[*i] != ' ') && (ft_isalnum(input[*i]) || input[*i] == '_'))
			{
				var[j++] = (input[(*i)++]);						
			}
			var[j]= 0;
			value = getenv(var);
			
			return value;
		}
		
	
		return "";
	}
	char *xpand_var(char *input, char *new_input, char *var)
	{
		int i =0;
		new_input=malloc(ft_strlen(input) + 5000); //free 
		if (!new_input) return NULL; 
		int j = 0;
		// int var_found = 0;
		while(input[i])
		{
			
			if(input[i] == '$')
			{
				var = find_var(input, &i,var);
				if(var != NULL)
				{
					strcpy(&new_input[j], var);
					j += strlen(var);
					// free(var);

				}
			}

		if(input[i] && input[i] == '\''){
			new_input[j++] = input[i++];
			while(input[i] && input[i] != '\'')
			{
				new_input[j++] = input[i++];
			}
			new_input[j++] = input[i++];
		}

		else{
				new_input[j++] = input[i++];
			}
			

		}
		new_input[j]= 0 ;
		// if (!var_found)
		// {
		// 	printf("Warning: No environment variable found for expansion.\n");
		// }
		return new_input; //free
		 
	}
	
	
	
int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_all *as;
	
	// t_lists	*head;
	// t_command *cmd =NULL;
	// char *ex;
	
   
	
	(void)argc;
	(void)argv;
	as = init_structs();
	 copy_envp(envp, as);
	// print_envp(as->cp_envp);
	// setup_signals();
	// char *path =getenv("PATH");
	while (1)
	{
		user_input = readline("new"); // add the path
		if (user_input == NULL)
		{
			write(1, "exit\n", 5); 
			// free(user_input);
		// free_memory(as);
			 break ;//free
		}
		//      if (user_input[0] == '\0') {
		//             free(user_input);
		//             continue ;
		//         }
		//       else{
		  add_history(user_input);
		  as->new_input = xpand_var(user_input, as->new_input, as->variable);
		  printf("%s\n",as->new_input);
		  split_input(as->new_input, &as->head); //here to add to all struct
		  print_list(as->head);
		  remove_quotes(as->head);
		
		
		split_cmds(as->head, &as->cmd);
		// print_list(head);
		print_cmds(as->cmd);
		
		free(user_input);
		
		
		
	
		
	}
	//   }
	printf("HI");
	 free_memory(as);

	
}