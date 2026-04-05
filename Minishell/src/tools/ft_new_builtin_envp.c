#include "../../incl/minishell.h"

t_builtin_envp	*ft_new_builtin_envp(char *key, char *value)
{
	t_builtin_envp	*new;

	new = malloc(sizeof(t_builtin_envp));
	if (!new)
		return (NULL);
	new->key = key;
	new->val = value;
	new->next = NULL;
	return (new);
}
