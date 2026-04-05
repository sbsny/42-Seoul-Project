#include "../../incl/minishell.h"

static bool	is_flag(t_token *token_node)
{
	int	i;

	i = 0;
	if (token_node->content[i] == '-')
	{
		i++;
		while (token_node->content[i] != '\0')
		{
			if (token_node->content[i] != 'n')
				return (false);
			i++;
		}
		if (token_node->content[0] == '-' && ft_strlen(token_node->content) == 1)
			return (false);
		else
			return (true);
	}
	return (false);
}

void	print_args(t_data *shell_state, int words)
{
	int		i;
	int		flag;
	bool	check_flag;
	t_token	*cursor_node;

	i = 1;
	flag = 0;
	check_flag = false;
	cursor_node = shell_state->tokens->next;
	while (i < words)
	{
		if (is_flag(cursor_node) == true && check_flag != true)
			flag = 1;
		else
		{
			printf("%s", cursor_node->content);
			if (i < words - 1)
				printf(" ");
			check_flag = true;
		}
		i++;
		cursor_node = cursor_node->next;
	}
	if (flag == 0)
		printf("\n");
}

int	builtin_echo(t_data *shell_state)
{
	int	words;

	words = count_cmd_word_tokens(shell_state);
	if (words == 1)
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	print_args(shell_state, words);
	g_exit_code = EXIT_SUCCESS;
	return (g_exit_code);
}
