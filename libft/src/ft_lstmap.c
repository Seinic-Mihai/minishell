/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:51:37 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/03 16:43:41 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cursor;
	t_list	*modif;

	cursor = lst;
	new = f(cursor);
	modif = new;
	while (cursor->next != NULL)
	{
		new->next = f(cursor->next);
		new = new->next;
		cursor = cursor->next;
	}
	return (modif);
}
