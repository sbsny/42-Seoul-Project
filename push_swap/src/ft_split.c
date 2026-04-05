/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:11:34 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 11:50:11 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	cnt_word(char *str)
{
	char	*tmp;
	size_t	cnt;

	cnt = 0;
	tmp = str;
	while (*tmp != 0)
	{
		while (*tmp != 0 && is_space(*tmp))
			++tmp;
		if (*tmp != 0 && !is_space(*tmp))
			++cnt;
		while (*tmp != 0 && !is_space(*tmp))
		{
			if ((*tmp >= '0' && *tmp <= '9') || *tmp == '+' || *tmp == '-')
				++tmp;
			else
				return (0);
		}
	}
	return (cnt);
}

static char	*save_word(char *str)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && !is_space(str[i]))
		++i;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = -1;
	while (str[++i] != 0 && !is_space(str[i]))
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

static char	**malloc_free(char **str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char	**ft_split(char const *swap_top)
{
	char	**words;
	size_t	i;

	if (!swap_top || !cnt_word((char *)swap_top))
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (cnt_word((char *)swap_top) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*swap_top != 0)
	{
		while (*swap_top != 0 && is_space(*swap_top))
			++swap_top;
		if (*swap_top != 0 && !is_space(*swap_top))
		{
			words[i] = save_word((char *)swap_top);
			if (!words[i++])
				return (malloc_free(words));
		}
		while (*swap_top != 0 && !is_space(*swap_top))
			++swap_top;
	}
	words[i] = NULL;
	return (words);
}
