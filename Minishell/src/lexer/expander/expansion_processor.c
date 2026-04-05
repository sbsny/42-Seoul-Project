#include "../../../incl/minishell.h"

static void	try_expansion(t_data *shell_state, t_lex *lex)
{
	t_builtin_envp	*builtin_env_cursor;

	builtin_env_cursor = shell_state->builtin_envp;
	while (builtin_env_cursor != NULL)
	{
		if (ft_strcmp(lex->buf, builtin_env_cursor->key) == 0)
		{
			free(lex->buf);
			lex->buf = NULL;
			lex->buf = ft_strjoin(lex->buf, builtin_env_cursor->val);
			return ;
		}
		builtin_env_cursor = builtin_env_cursor->next;
	}
	free(lex->buf);
	lex->buf = NULL;
}

static void	try_double_quote_exp(t_data *shell_state, t_lex *lex, char *quote_buf)
{
	t_builtin_envp	*builtin_env_cursor;

	builtin_env_cursor = shell_state->builtin_envp;
	while (lex->c != CHAR_DOLLAR && lex->c != CHAR_DOUBLE_QUOTE
		&& lex->c != CHAR_SINGLE_QUOTE && lex->c != CHAR_SLASH && lex->c != CHAR_SPACE)
	{
		quote_buf = ft_join_char(quote_buf, lex->c);
		lex->i++;
		lex->c = shell_state->input[lex->i];
	}
	if (quote_buf != NULL)
	{
		while (builtin_env_cursor != NULL)
		{
			if (ft_strcmp(quote_buf, builtin_env_cursor->key) == 0)
			{
				lex->buf = ft_strjoin(lex->buf, builtin_env_cursor->val);
				break ;
			}
			builtin_env_cursor = builtin_env_cursor->next;
		}
		free(quote_buf);
		quote_buf = NULL;
	}
}

void	expand_parameter(t_data *shell_state, t_lex *lex)
{
	bool	is_sep;
	char	*quote_buf;

	quote_buf = NULL;
	is_sep = check_sep(shell_state, lex->c);
	if (lex->double_quote_mode == true)
		try_double_quote_exp(shell_state, lex, quote_buf);
	else
	{
		while (is_sep == false && lex->c != '\0')
		{
			is_sep = check_sep(shell_state, lex->c);
			if (is_sep == true || lex->c == CHAR_SLASH)
				break ;
			lex->buf = ft_join_char(lex->buf, lex->c);
			lex->i++;
			lex->c = shell_state->input[lex->i];
		}
		if (lex->buf != NULL)
			try_expansion(shell_state, lex);
	}
}

static void	handle_expandable_parameter(t_data *shell_state, t_lex *lex)
{
	bool	is_sep;

	lex->i++;
	lex->c = shell_state->input[lex->i];
	is_sep = check_sep(shell_state, lex->c);
	if (lex->c == '?')
		expand_last_return(shell_state, lex);
	else if (is_sep == true || lex->c == '\0')
	{
		if (lex->c == CHAR_SINGLE_QUOTE || lex->c == CHAR_DOUBLE_QUOTE)
		{
			if (lex->single_quote_mode == true
				|| lex->double_quote_mode == true)
				lex->buf = ft_join_char(lex->buf, CHAR_DOLLAR);
		}
	}
	else
		expand_parameter(shell_state, lex);
	if (lex->buf != NULL && lex->double_quote_mode == false)
		append_token(shell_state, lex);
}

void	handle_expansion(t_data *shell_state, t_lex *lex)
{
	lex->expansion = true;
	if (lex->buf != NULL && lex->double_quote_mode == false)
		append_token(shell_state, lex);
	if (shell_state->input[lex->i + 1] == CHAR_SPACE || shell_state->input[lex->i + 1] == '\0')
	{
		handle_one_dollar(shell_state, lex);
		return ;
	}
	else if (shell_state->input[lex->i + 1] == CHAR_DOLLAR)
	{
		handle_multiple_dollars(shell_state, lex);
		return ;
	}
	else
		handle_expandable_parameter(shell_state, lex);
	lex->expansion = false;
}
