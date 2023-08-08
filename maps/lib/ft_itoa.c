/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:31:54 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/15 19:41:57 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	ssize_t		i;
	char		*str;
	long int	nb;

	nb = (long int)n;
	i = ft_count(nb);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (i - 1 >= 0 && nb > 0)
	{
		str[i-- - 1] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
