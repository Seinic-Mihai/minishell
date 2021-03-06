/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tab_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:50:16 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/19 16:05:55 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_tab.h"

int			t_tab_free(t_tab *tab)
{
	if (tab->max_len > 0)
	{
		free(tab->data);
		tab->max_len = 0;
		tab->size = 0;
	}
	return (0);
}
