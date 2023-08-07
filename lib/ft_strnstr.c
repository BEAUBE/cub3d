/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:12:05 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/06 23:44:44 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (little[j] == big[i])
		{
			while (big[i] && (little[j] == big[i]) && (i < len))
			{
				if (little[j + 1] == 0)
					return ((char *)big + (i - j));
				i++;
				j++;
			}
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
