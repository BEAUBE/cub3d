/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:46:51 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/15 19:36:44 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_line(char *s, char c)
{
	size_t	i;
	size_t	line;

	i = 0;
	line = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || !s[i + 1])
			line++;
		i++;
	}
	return (line);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_line(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s && *s == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j++] = ft_substr(s, i, ft_len(&s[i], c));
			i += ft_len(&s[i], c);
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
