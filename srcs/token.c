#include "../includes/minishell.h"

void	print_list(t_lists *head)
{
	t_lists	*current;
	int		i;

	current = head;
	i = 1;
	while (current != NULL)
	{
		printf("Token[%d] %s, type: %d\n", i, current->value, current->type);
		current = current->next;
		i++;
	}
}

t_lists	*find_last_node(t_lists *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

int	add_node(t_lists **head, char *input)
{
	t_lists	*node;
	t_lists	*last_node;

	if (!input)
		return -1;
	node = malloc(sizeof(t_lists)); // free t_lists function
	if (!node)
		return -1;
	node->value = input; 
	if (!node->value)
	{
		free(node); //shall we add it in the free function?
		return -1;
	}
	
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		last_node = find_last_node(*head);
		last_node->next = node;
		node->prev = last_node;
	}
	return 0;
}

void	init_token(t_token *token)
{
	token->start = 0;
	token->end = 0;
	token->value = NULL;
}
