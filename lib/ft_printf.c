/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:51:48 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/28 22:44:55 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *type, ...)
{
	va_list	li;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(li, type);
	while (type[i])
	{
		if (type[i] == '%')
		{
			size += ft_type(type[++i], li);
			i++;
		}
		else if (type[i] != '%')
			size += ft_putchar(type[i++]);
	}
	va_end(li);
	return (size);
}
