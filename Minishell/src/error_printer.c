#include "../incl/minishell.h"

void	print_error(int error)
{
	if (error == ERR_SINGLE_QUOTE_MISSING)
		printf("minishell:	syntax error. Missing '\n");
	else if (error == ERR_DOUBLE_QUOTE_MISSING)
		printf("minishell:	syntax error. Missing \"\n");
	else if (error == ERR_EXIT)
		printf("minishell: exit: too many arguments\n");
	else if (error == ERR_INVALID_PATH)
		printf("minishell: Invalid path_name or directory:");
	else if (error == ERR_OLDPWD)
		printf("minishell: builtin_cd: OLDPWD not set\n");
	else if (error == ERR_ENV)
		printf("minishell: builtin_env: too many arguments\n");
}

void	print_token_error(int error, t_token *token_node)
{
	char	*redir;

	if (token_node->next == NULL)
		redir = ft_strdup("newline");
	else
		redir = ft_strdup(token_node->next->content);
	if (error == ERR_PIPE_SYNTAX)
		printf("minishell: syntax error near unexpected token_node `||'\n");
	else if (error == ERR_REDIR_SYNTAX)
		printf("minishell: syntax error near unexpected token_node `%s'\n", redir);
	free(redir);
	redir = NULL;
}

int	exec_error(int error, char *s)
{
	if (error == ERR_EXPORT)
		printf("minishell: builtin_export: `%s': not a valid identifier\n", s);
	else if (error == ERR_EXIT_ARG)
		printf("minishell: exit: %s: numeric argument required\n", s);
	else if (error == ERR_CMD)
		printf("minishell: command: %s: not found\n", s);
	else if (error == EXIT_CMD_NOT_FOUND)
		printf("minishell: %s: command not found\n", s);
	else if (error == ERR_PATH)
		printf("minishell: %s: No such path_name or directory\n", s);
	else if (error == ERR_UNSET)
		printf("minishell: builtin_unset: `%s': not a valid identifier\n", s);
	else if (error == ERR_PERMISSION)
		printf("minishell: %s: Permission denied\n", s);
	else if (error == ERR_EMPTY_KEY)
		printf("minishell: builtin_cd: %s not set\n", s);
	return (1);
}
