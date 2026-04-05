#ifndef BUILTINS_H
# define BUILTINS_H

# include <sys/types.h>
# include <unistd.h>
# include "structs.h"
# include <errno.h>

int		builtin_cd(t_data *shell_state);
int		builtin_echo(t_data *shell_state);
int		builtin_env(t_data *shell_state);
int		builtin_exit(t_data *shell_state);
int		builtin_export(t_data *shell_state);
int		builtin_pwd(void);
int		builtin_unset(t_data *shell_state);
char	*extract_builtin_env_key(char *s, int *i);
int		fill_empty_builtin_pwd(t_data *shell_state, char **builtin_pwd_path,
			t_builtin_envp **builtin_pwd, t_builtin_envp **old);
void	print_builtin_export_builtin_env(t_data *shell_state);
int		resolve_home_path(char **s, t_data *shell_state);
int		update_working_dirs(t_data *shell_state);
int		validate_builtin_export_keys(char **s, int mode);

#endif
