#include "../includes/minishell.h"

int		si = 0;



	// void	token_type(t_lists *node)
	// {
	// 	if (node->value[0] == '"')
	// 	{
	// 		node->type = 2;
	// 	}
	// 	else if (parameter_char(node->value[0]))
	// 	{
	// 		node->type = 1;
	// 	}
	// 	else if (node->value[0] == '/' || ft_isalpha(node->value[0]))
	// 	{
	// 		node->type = 0;
	// 	}
	// 	else
	// 	{
	// 		printf("invalid type");
	// 		exit(1); // write exit minishell function
	// 	}
	// }

void	split_command(char *input)
{
	t_token	token;
	t_lists	*head;
	int		i;

	head = NULL;
	i = 0;
	init_token(&token);
	while (input[i])
	{
		token.start = i;
		if (input[i] == '"')
		{
			i = handle_d_quotes(input, i, &token, &head);
			// shall i handle unclosed quote?
		}
		else if (input[i] == '\'')
		{
			i = handle_s_quotes(input, i, &token, &head);
		}
		else if (is_space(input[i]))
		{
			printf("space\n");
			i++;
			continue ;
		}
		else if (parameter_char(input[i]))
		{
			printf("para\n");
			i = is_parameter(input, i, &token, &head);
		}
		else
		{
			printf("str\n");
			i = str(input, i, &token, &head);
		}
		i++;
	}
	print_list(head);
}
void	handle_sigint(int sig)
{
	(void)sig;
	si = 1;
	write(1, "\nminishell> ", 12);
}
void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, NULL);
}
int	main(int argc, char **argv, char **envp)
{
	char	*user_input;

	(void)argc;
	(void)argv;
	(void)envp;
	setup_signals();
	while (1)
	{
		user_input = readline("minishell> "); // add the path
		if (si == 1)
		{
			si = 0;
			free(user_input);
			continue ;
		}
		if (user_input == NULL)
		{
			write(1, "exit\n", 5);
			break ;
		}
		//      if (user_input[0] == '\0') {
		//             free(user_input);
		//             continue ;
		//         }
		//       else{
		  add_history(user_input);
		split_command(user_input);
	}
	//   }
	free(user_input);
}
