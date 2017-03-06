/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tab_reserve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:44:10 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/01 13:48:38 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_tab.h"

int		t_tab_reserve(t_tab *tab, size_t size)
{
	void *tmp;

	if (size > tab->max_len - tab->size)
	{
		tab->max_len = size + tab->size;
		if ((tmp = malloc(tab->type_size * tab->max_len)) == NULL)
			return (1);
		ft_bzero(tmp, tab->max_len * tab->type_size);
		if (tab->data != NULL)
		{
			ft_memcpy(tmp, tab->data, tab->size * tab->type_size);
			free(tab->data);
		}
		tab->data = tmp;
	}
	return (0);
}
