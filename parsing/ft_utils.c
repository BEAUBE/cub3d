/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:28:47 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/14 23:30:27 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_split_all(char **id)
{
	char	**tab;
	char	*tmp;
	int		i;

	i = 2;
	tmp = ft_strdup(id[1]);
	tab = ft_calloc(sizeof (char *), 3);
	tab[0] = ft_strdup(id[0]);
	while (id[i])
	{
		tmp = ft_strjoin(tmp, id[i]);
		i++;
	}
	tab[1] = ft_strdup(tmp);
	tab[2] = 0;
	ft_free_tab(id);
	free(tmp);
	return (tab);
}
