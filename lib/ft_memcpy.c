/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 06:07:29 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/15 18:42:45 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	tmp1 = (char *)dest;
	tmp2 = (char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (tmp1);
}
