/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tab_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:51:03 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/19 16:01:10 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_tab.h"

int			t_tab_expand(t_tab *tab, size_t new_max_size)
{
	t_tab	tmp;

	tmp = NEW_TAB(tab->type_size);
	if (tab->max_len > 0 && tab->data != NULL)
	{
		if (t_tab_reserve(&tmp, tab->max_len))
			return (1);
		ft_memcpy(tmp.data, tab->data, tab->max_len);
		t_tab_free(tab);
		if (t_tab_reserve(tab, new_max_size))
			return (1);
		ft_memcpy(tab->data, tmp.data, tmp.max_len);
		t_tab_free(&tmp);
	}
	return (0);
}
