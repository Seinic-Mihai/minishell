/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tab_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:51:52 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/20 15:27:11 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_tab.h"

int			t_tab_add(t_tab *tab, void *data, size_t datalen)
{
	size_t	new_max_len;

	if (tab->size + datalen > tab->max_len)
	{
		new_max_len = tab->max_len;
		if (new_max_len == 0)
			new_max_len = 1;
		while (tab->size + datalen > new_max_len)
			new_max_len *= TAB_EXPAND;
		if (t_tab_reserve(tab, new_max_len - tab->size))
			return (1);
	}
	ft_memcpy(tab->data + tab->size * tab->type_size, data,
			datalen * tab->type_size);
	tab->size += datalen;
	return (0);
}
