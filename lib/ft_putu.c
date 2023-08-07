/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:53:44 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/28 22:37:57 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putu(unsigned long long nb, char *base)
{
	size_t	count;
	int		i;
	int		tab[100];

	count = 0;
	i = 0;
	if (nb == 0)
		count = ft_putchar('0');
	while (nb >= 1)
	{
		tab[i++] = base[nb % 10];
		nb /= 10;
	}
	count += i;
	i--;
	while (i >= 0)
		ft_putchar(tab[i--]);
	return (count);
}
