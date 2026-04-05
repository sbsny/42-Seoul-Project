#include "../../incl/minishell.h"

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	j;
	int	new_word;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	new_word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && new_word == 0)
		{
			j++;
			new_word = 1;
		}
		else if (str[i] == c)
			new_word = 0;
		i++;
	}
	return (j);
}

char	*ft_copy_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) *(end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_split_string(char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		new_word;

	i = 0;
	j = 0;
	new_word = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && new_word == -1)
			new_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && new_word >= 0)
		{
			split[j] = ft_copy_word(s, (new_word), i);
			new_word = -1;
			j++;
		}
		i++;
	}
	split[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	ft_split_string(split, s, c);
	return (split);
}
