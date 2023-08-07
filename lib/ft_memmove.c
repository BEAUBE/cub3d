/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:05:40 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/15 18:46:49 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *) dest;
	s = (char *) src;
	if (!dest && !src)
		return (dest);
	if (d < s)
	{
		ft_memcpy(d, s, n);
		return (d);
	}
	while (n--)
		*(d + n) = *(s + n);
	return (d);
}
