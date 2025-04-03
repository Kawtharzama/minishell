#include "../includes/minishell.h"

int init_envp(t_all *as)
	{
		
		as->cp_envp = malloc(sizeof(t_envp)); //free
		if (!as->cp_envp)
        	return (-1);
		as->cp_envp->tmp_envp = NULL;
		return 1;
	}
// int init_head(t_all *as)
// {
    
// }
t_all *init_structs(){
	t_all *as;
	as = malloc(sizeof(t_all));
	if(!as){
		return NULL;
		} //exit
	init_envp(as);
	as->cmd = NULL; //ANY PART OF T_ALL TO null
	// as->cp_envp = NULL;
	as->head = NULL;
	as->new_input = NULL;
    // init_head(as);
  

	return (as);
	}