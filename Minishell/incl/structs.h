#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

# define BUILTIN_COUNT		7
# define REDIRECTION_COUNT	4

typedef struct s_token
{
	char			*content;
	int				flag;
	bool			join;
	struct s_token	*next;
}		t_token;

typedef struct s_builtin_envp
{
	char					*key;
	char					*val;
	bool					equal;
	struct s_builtin_envp	*next;
}		t_builtin_envp;

typedef struct s_builtins
{
	char		*names[BUILTIN_COUNT];
	int			(*funcs[BUILTIN_COUNT])(void *);
	char		*home;
}		t_builtins;

typedef struct s_lex
{
	int		i;
	char	c;
	char	*buf;
	int		flag;
	bool	single_quote_mode;
	bool	double_quote_mode;
	bool	expansion;
}		t_lex;

typedef struct s_fd
{
	int		in;
	int		out;
	int		std_in;
	int		std_out;
	char	**hdoc;
	int		hdoc_index;
}		t_fd;

typedef struct s_exec
{
	char	**cmd;
	char	*path;
	int		cmd_num;
	int		last_cmd;
	bool	no_cmd;
}		t_exec;

typedef struct s_data
{
	t_builtins			*builtins;
	char				**builtin_env;
	t_builtin_envp		*builtin_envp;
	t_exec				*exec;
	t_fd				*fd;
	char				*input;
	pid_t				pid;
	int					pipe[2];
	int					*redir;
	char				*sep;
	t_token				*tokens;
	bool				lex_error;
	bool				parse_error;
	bool				exec_error;
	bool				exit_minishell;
}		t_data;

#endif
