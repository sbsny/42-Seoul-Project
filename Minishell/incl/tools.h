#ifndef TOOLS_H
# define TOOLS_H

# include "structs.h"

void	ft_add_builtin_envp_back(t_builtin_envp **lst, t_builtin_envp *new);
void	ft_append_token_back(t_token **lst, t_token *new);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_cleansplit(char **split);
bool	ft_check_plus(char *s);
void	ft_del_first_token(t_data **shell_state);
t_builtin_envp	*ft_getbuiltin_envp(t_data *shell_state, char *find);
int		ft_haschar(char *s, char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isnumber(char *s, long long sum, int i);
int		ft_isprint(int c);
char	*ft_itoa(int n);
char	*ft_join_char(char *buf, char c);
char	*ft_join_tilde(char *buf, char *cursor_node, int flag);
void	ft_lstclear(t_builtin_envp **lst);
t_builtin_envp	*ft_new_builtin_envp(char *key, char *value);
t_token	*ft_new_token(char *content, int flag);
char	**ft_split(char const *s, char c);
int		ft_splitlen(char **s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *buf, char *cursor_node);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char *str, char delim);
int		identify_builtin_cmd(t_data *shell_state);
int		print_list(t_token *shell_state);
int		count_cmd_word_tokens(t_data *shell_state);
int		count_pipeline_cmds(t_data *shell_state);

#endif
