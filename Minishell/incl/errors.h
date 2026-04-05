#ifndef ERRORS_H
# define ERRORS_H

# include "structs.h"

# define ERR_SINGLE_QUOTE_MISSING		1
# define ERR_DOUBLE_QUOTE_MISSING		2
# define ERR_REDIR_SYNTAX				3
# define ERR_EXIT						4
# define ERR_CMD						5
# define ERR_EXIT_ARG					6
# define ERR_INVALID_PATH				7
# define ERR_EXPORT					8
# define ERR_OLDPWD					9
# define ERR_UNSET					10
# define ERR_PATH						11
# define ERR_PERMISSION				12
# define ERR_EMPTY_KEY				13
# define ERR_ENV						14

# define ERR_PIPE_SYNTAX				258

# define EXIT_CMD_NOT_FOUND				127
# define EXIT_INVALID_ARG			255
# define EXIT_SIGINT				130

int		exec_error(int error, char *s);
void	print_error(int error);
void	print_token_error(int error, t_token *token_node);

#endif
