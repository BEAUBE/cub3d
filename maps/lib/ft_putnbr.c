/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:51:04 by slepetit          #+#    #+#             */
/*   Updated: 2022/12/28 05:51:14 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int			i;
	int			tab[100];
	long int	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb == 0)
		ft_putchar('0');
	while (nb > 0)
	{
		tab[i] = nb % 10;
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(tab[i] + 48);
		i--;
	}
}
