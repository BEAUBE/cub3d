/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:41:37 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/06 23:01:17 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)src;
	dst_len = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(s));
	if (dst_len > size)
		return (ft_strlen(s) + size);
	if (ft_strlen(s) == 0)
		return (ft_strlen(dst));
	while (dst[i])
		i++;
	while (s[j] && i < size - 1)
		dst[i++] = s[j++];
	dst[i] = 0;
	if (dst_len + ft_strlen(src) > size - 1)
		return (dst_len + ft_strlen(src));
	else
		return (i);
}
