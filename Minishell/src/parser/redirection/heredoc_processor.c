#include "../../../incl/minishell.h"

static void	create_heredoc_file(t_data *shell_state)
{
	char	*path;
	char	*index;
	char	*hdoc;

	path = ft_strdup("/cursor_node/");
	index = ft_itoa(shell_state->fd->hdoc_index);
	hdoc = ft_strjoin(path, index);
	free(index);
	index = NULL;
	shell_state->fd->hdoc[shell_state->fd->hdoc_index] = ft_strdup(hdoc);
	shell_state->fd->in = open(hdoc, O_CREAT | O_RDWR | O_TRUNC, FILE_DEFAULT_RIGHTS);
	if (shell_state->fd->in < 0 || access(hdoc, F_OK) < 0 || access(hdoc, R_OK) < 0)
	{
		perror(NULL);
		shell_state->parse_error = true;
	}
	free(hdoc);
	hdoc = NULL;
}

static void	read_heredoc_input(t_data *shell_state, t_token *token_node)
{
	char	*input;
	bool	lim_found;

	lim_found = false;
	while (lim_found == false)
	{
		configure_signal_mode(SIGNAL_MODE_HEREDOC);
		input = readline("> ");
		if (!input)
			break ;
		if (ft_strcmp(input, token_node->content) == 0)
			lim_found = true;
		else
		{
			input = ft_strjoin(input, "\n");
			if (write(shell_state->fd->in, input, ft_strlen(input)) < 0)
			{
				perror(token_node->content);
				exit(EXIT_FAILURE);
			}
		}
		free(input);
		input = NULL;
	}
	exit(EXIT_SUCCESS);
}

static void	write_heredoc_file(t_data *shell_state, t_token *token_node)
{
	int	status;

	status = 0;
	shell_state->pid = fork();
	if (shell_state->pid < 0)
		perror(NULL);
	else if (shell_state->pid == 0)
		read_heredoc_input(shell_state, token_node);
	waitpid(shell_state->pid, &status, 0);
	if (WIFEXITED(status))
	{
		g_exit_code = WEXITSTATUS(status);
		if (g_exit_code == EXIT_FAILURE)
			shell_state->parse_error = true;
	}
}

void	parse_hdocs(t_data *shell_state)
{
	t_token	*cursor_node;

	cursor_node = shell_state->tokens;
	while (cursor_node != NULL)
	{
		if (cursor_node->flag == TOKEN_HEREDOC)
		{
			create_heredoc_file(shell_state);
			write_heredoc_file(shell_state, cursor_node);
			if (shell_state->parse_error == true)
			{
				clear_heredoc_files(shell_state);
				g_exit_code = ERR_PIPE_SYNTAX;
				return ;
			}
			close(shell_state->fd->in);
			shell_state->fd->in = 0;
			shell_state->fd->hdoc_index++;
		}
		cursor_node = cursor_node->next;
	}
}
