/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:48:48 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/02 16:57:36 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	int			tab[100];
	long int	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb == 0)
		ft_putchar_fd('0', fd);
	while (nb > 0)
	{
		tab[i] = nb % 10;
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd(tab[i] + 48, fd);
		i--;
	}
}
