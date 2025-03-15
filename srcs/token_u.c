#include "../includes/minishell.h"
int	handle_d_quotes(char *input, int i, t_token *token, t_lists **head)
{
	token->start = i;
	i++;
	while (input[i] != '"' && input[i])
	{
		i++;
	}
	token->end = i;
	token->value = ft_substr(input, token->start, (token->end - token->start
				+ 1));
	if (!token->value)
	{
		printf("Memory allocation failed for token.value\n");
		return (i);
	}
	add_node(head, token->value);
	return (i);
}

int	handle_s_quotes(char *input, int i, t_token *token, t_lists **head)
{
	token->start = i;
	i++;
	while (input[i] != '\'' && input[i])
	{
		i++;
	}
	token->end = i;
	token->value = ft_substr(input, token->start, (token->end - token->start
				+ 1));
	if (!token->value)
	{
		printf("Memory allocation failed for token.value\n");
		return (i);
	}
	add_node(head, token->value);
	return (i);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	
	return (0);
}

int	parameter_char(char c)
{
	if (c == '|' || c == '>' || c == '<')
	{
		return (1);
	}
	return (0);
}

int	is_parameter(char *input, int i, t_token *token, t_lists **head)
{
	token->start = i;
	if (input[i + 1] && input[i] == input[i + 1] && input[i + 1] != '|')
	{
		i++;
		if (input[i + 1] && input[i] == input[i + 1])
		{
			printf("syntax error near unexpected token '%c'\n", input[i]);
			exit(1); // add exit minishell function
		}
	}
	token->end = i;
	token->value = ft_substr(input, token->start, (token->end - token->start
				+ 1));
	if (!token->value)
	{
		printf("Memory allocation failed for token.value\n");
		return (i);
	}
	add_node(head, token->value);
	return (i);
	return (i);
}

int	str(char *input, int i, t_token *token, t_lists **head)
{
	token->start = i;
	while (input[i] && !is_space(input[i]) && !parameter_char(input[i])
		&& input[i] != '"' && input[i] != '\'')
	{
		i++;
	}
	token->end = i;
	token->value = ft_substr(input, token->start, (token->end - token->start));
	if (!token->value)
	{
		printf("Memory allocation failed for token.value\n");
		return (i - 1);
	}
	add_node(head, token->value);
	return (i - 1);
}
