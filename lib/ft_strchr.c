/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:14:07 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/01 18:08:17 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	if ((char)c == 0)
		return (p + ft_strlen(p));
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&(p[i]));
		i++;
	}
	return (NULL);
}
