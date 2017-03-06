/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tab.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:39:49 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/19 16:36:40 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TAB_H
# define T_TAB_H
# include "libft.h"
# define TAB_INIT_SIZE 8
# define TAB_EXPAND 2
# define NEW_TAB(type_size) (t_tab){NULL, type_size, 0, 0}

typedef struct	s_tab
{
	void		*data;
	size_t		type_size;
	size_t		size;
	size_t		max_len;
}				t_tab;

int				t_tab_init(t_tab *tab);
int				t_tab_reserve(t_tab *tab, size_t size);
int				t_tab_free(t_tab *tab);
int				t_tab_expand(t_tab *tab, size_t new_max_size);
int				t_tab_add(t_tab *tab, void *data, size_t datalen);
#endif
