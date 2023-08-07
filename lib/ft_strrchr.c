/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:34:17 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/01 18:14:52 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	i;
	char		*p;

	i = 0;
	p = (char *)s;
	if ((char)c == 0)
		return (p + ft_strlen(p));
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&(p[i]));
		i--;
	}
	return (NULL);
}
