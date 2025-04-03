#include "../includes/minishell.h"
int closing_qoutes(char *input, int i){
	char quote_type;
	int flag = 1;
    quote_type = input[i];
	i++;
while (input[i])
	{
		if ((input[i] == '"' || input[i] == '\'') && flag == 0)
		{
			quote_type = input[i];
			flag = 1;
		}
		else if(input[i] == quote_type && flag == 1)
		{ 
			flag = 0;
			if (input[i + 1] && input[i + 1] != ' ' && !is_parameter(input[i + 1]))
			{
				;
			}
			else{
				break;
			}
		}
	
		i++;
	}
    if (flag  == 1)
    {
        printf("synatx error unclosed quote\n");   
        return (i); //change it 
    }
return i;
}
int	handle_quotes(char *input, int i, t_token *token, t_lists **head)
{
    
	token->start = i;
	i = closing_qoutes(input,i);
	if (i == -1)
		return (-1);
	
	token->end = i;
	token->value = ft_substr(input, token->start, (token->end - token->start
				+ 1));
	if (!token->value)
	{
		printf("Memory allocation failed for token.value\n");
		return (-1);
	}
	add_node(head, token->value);
	// free(token->value);
	return (i);
}

void split_input(char *input, t_lists **head)
{
	t_token	token;
	*head = NULL;
	
	int		i;

	i = 0;
	init_token(&token);
	while (input[i])
	{
		token.start = i;
		if (input[i] == '"' || input[i] == '\'')
		{
			i = handle_quotes(input, i, &token, head);

		}
			else if (input[i] == ' ') 
			;
	
		else if (is_parameter(input[i]))
		{
			i = parameter_token(input, i, &token, head);

		}
		else
		{
			i = str(input, i, &token, head);

		}
		if (i == -1)
			{exit(1);} //free
	i++;
	}
	token_types(*head);

}
