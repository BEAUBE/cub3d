/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:53:06 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/28 22:39:12 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puthexa(unsigned long nb, char *base)
{
	size_t	count;
	int		i;
	int		tab[20];

	count = 0;
	i = 0;
	if (nb == 0)
		count = ft_putchar('0');
	while (nb > 0)
	{
		tab[i++] = base[nb % 16];
		nb /= 16;
	}
	count += i;
	i--;
	while (i >= 0)
		ft_putchar(tab[i--]);
	return (count);
}
