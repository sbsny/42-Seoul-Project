#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <readline/history.h>
# include <stdbool.h>
# include <termios.h>
# include <sys/wait.h>

# include "tools.h"
# include "structs.h"
# include "builtins.h"
# include "errors.h"

# ifndef SIZE_MAX
#  define SIZE_MAX __SIZE_MAX__
# endif

# define CHAR_SPACE				' '
# define CHAR_SINGLE_QUOTE		'\''
# define CHAR_DOUBLE_QUOTE		'\"'
# define CHAR_DOLLAR				'$'
# define CHAR_REDIRECT_IN		'<'
# define CHAR_REDIRECT_OUT		'>'
# define CHAR_PIPE				'|'
# define CHAR_SLASH				'/'

# define TOKEN_WORD				1
# define TOKEN_REDIRECT_IN		2
# define TOKEN_REDIRECT_OUT		3
# define TOKEN_APPEND			4
# define TOKEN_HEREDOC			5
# define TOKEN_PIPE				6

# define SIGNAL_MODE_CHILD		0
# define SIGNAL_MODE_MAIN		1
# define SIGNAL_MODE_HEREDOC				2
# define FILE_DEFAULT_RIGHTS				0644

extern int	g_exit_code;

void	allocate_shell_context(t_data *shell_state);
void	backup_stdio_fds(t_data *shell_state);
void	bootstrap_builtin_env_list(t_data *shell_state, char **builtin_envp);
void	bootstrap_shell(t_data *shell_state, char **builtin_envp);
void	load_builtin_handlers(t_data *shell_state);
void	load_builtin_names(t_data *shell_state);
void	reset_exec_state(t_data *shell_state);
void	reset_fd_state(t_data *shell_state);

void	clear_builtin_env_list(t_data *shell_state);
void	clear_builtin_table(t_data *shell_state);
void	clear_heredoc_files(t_data *shell_state);
void	clear_token_stream(t_data *shell_state);
void	free_cmd_and_path(t_data *shell_state);
void	shutdown_shell(t_data *shell_state);

void	capture_prompt_history(t_data *shell_state);

void	abort_lexing(t_data *shell_state, t_lex *lex);
void	append_token(t_data *shell_state, t_lex *lex);
bool	check_sep(t_data *shell_state, char c);
void	expand_last_return(t_data *shell_state, t_lex *lex);
void	expand_parameter(t_data *shell_state, t_lex *lex);
bool	find_redirections(t_lex *lex);
void	handle_double_quotes(t_data *shell_state, t_lex *lex);
void	handle_expansion(t_data *shell_state, t_lex *lex);
void	handle_multiple_dollars(t_data *shell_state, t_lex *lex);
void	handle_one_dollar(t_data *shell_state, t_lex *lex);
void	handle_redirections(t_data *shell_state, t_lex *lex);
void	handle_single_quotes(t_data *shell_state, t_lex *lex);
void	handle_words(t_data *shell_state, t_lex *lex);
bool	is_quote_unclosed(t_data *shell_state, t_lex *lex);
void	scan_input_tokens(t_data *shell_state, t_lex *lex);
void	tokenize_input(t_data *shell_state);

void	analyze_tokens(t_data *shell_state);
void	append(t_data *shell_state, t_token *token_node);
void	apply_redirections(t_data *shell_state);
void	close_fds_in_out(t_data *shell_state);
void	close_unused_fd_in(t_data *shell_state);
void	close_unused_fd_out(t_data *shell_state);
void	collapse_joinable_tokens(t_data *shell_state);
void	collapse_redirection_targets(t_data *shell_state);
void	delete_words(t_data *shell_state);
bool	has_redirection_syntax_error(t_data *shell_state, t_token *token_node);
bool	is_redirection_token(t_data *shell_state, int flag);
void	normalize_join_flags(t_data *shell_state);
void	parse_hdocs(t_data *shell_state);
void	redirect_from_hdoc(t_data *shell_state);
void	redirect_in(t_data *shell_state, t_token *token_node);
void	redirect_out(t_data *shell_state, t_token *token_node);
void	validate_input_fd(t_data *shell_state, t_token *token_node);
void	validate_output_fd(t_data *shell_state, t_token *token_node);
void	validate_pipe_sequence(t_data *shell_state);

char	**extract_cmd_from_path(t_data *shell_state);
char	**get_cmd(t_data *shell_state);
char	*get_cmd_path(t_data *shell_state);
void	update_child_exit_code(t_data *shell_state);
void	run_token_pipeline(t_data *shell_state);

void	forward_pipe_input(t_data *shell_state);
void	restore_stdio_fds(t_data *shell_state);
void	run_external_command(t_data *shell_state);
void	run_last_builtin(t_data *shell_state, int builtin);
void	run_pipeline_last_stage(t_data *shell_state);
void	run_pipeline_stage(t_data *shell_state);
void	run_stage_builtin(t_data *shell_state, int builtin);
void	sync_pipeline_exit_code(t_data *shell_state);
void	wire_last_redirection(t_data *shell_state);
void	wire_stage_redirection(t_data *shell_state);

void	configure_signal_mode(int flag);

#endif
