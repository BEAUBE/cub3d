/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:41:38 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/01 12:06:03 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	s = (char *)src;
	len = ft_strlen(s);
	if (size == 0)
		return (len);
	while (s[i] && i < size - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}
