/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:11:28 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/13 23:03:12 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	while (s1[j])
	{
		if (ft_strrchr(set, s1[j]) == NULL)
			break ;
		j--;
	}
	cpy = ft_substr(s1, i, j - i + 1);
	return (cpy);
}
