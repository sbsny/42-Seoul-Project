/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunglee <sunglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:28:51 by sunglee           #+#    #+#             */
/*   Updated: 2023/02/06 13:28:53 by sunglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_words(char *s, char c)
{
	int	i;
	int	j;
	int	is_set;

	is_set = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && is_set == 0)
		{
			is_set = 1;
			j++;
		}
		else if (s[i] == c && is_set == 1)
			is_set = 0;
		i++;
	}
	return (j);
}

int	ft_len_word(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		nbr_words;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nbr_words = ft_nbr_words((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (nbr_words)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_substr((char *)s, 0, ft_len_word((char *)s, c));
		s = s + ft_len_word((char *)s, c);
		i++;
		nbr_words--;
	}
	tab[i] = NULL;
	return (tab);
}
