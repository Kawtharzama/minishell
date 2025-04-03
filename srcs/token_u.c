#include "../includes/minishell.h"

void remove_quotes(t_lists *head)
{
    int i, j, q;
    char c;

    while (head != NULL && head->type == WORD)
    {
        if (head->value == NULL || head->value[0] == '\0')
        {
            head = head->next;
            continue;
        }

        i = 0;
        j = 0;
        q = 0;

        while (head->value[i] != '\0')
        {
            if (q == 0 && (head->value[i] == '"' || head->value[i] == '\''))
            {
                q = 1;
                c = head->value[i++];
                while (head->value[i] != '\0' && head->value[i] != c)
                {
                    head->value[j++] = head->value[i++];
                }
                if (head->value[i] == c) i++; // Skip closing quote
                q = 0;
            }
            else
            {
                head->value[j++] = head->value[i++];
            }
        }

        head->value[j] = '\0'; // Null-terminate the string
        head = head->next;
    }
}

int	is_parameter(char c)
{
	if (c == '|' || c == '>' || c == '<')
	{
		return (1);
	}
	return (0);
}

int	parameter_token(char *input, int i, t_token *token, t_lists **head)
{
	token->start = i;
	if (input[i + 1] && input[i] == input[i + 1] && input[i + 1] != '|')
		i++;
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

int	str(char *input, int i, t_token *token, t_lists **head)
{
	token->start = i;
	while (input[i] && input[i] !=' ' && !is_parameter(input[i]))
		
	{
		if (input[i] == '"' || input[i] == '\'')
		{i = closing_qoutes(input,i);}
		i++;
	}
	token->end = i;
	token->value = ft_substr(input, token->start, (token->end - token->start));
	if (!token->value)
	{
		printf("Memory allocation failed for token.value\n");
		return (-1);
	}
	add_node(head, token->value);
	// free(token->value);
	return (i - 1);
}
