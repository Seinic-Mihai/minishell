/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:39:50 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/28 12:45:15 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*tmp;

	head = (*alst)->next;
	if (alst != NULL && del != NULL && *alst != NULL)
	{
		while (head != NULL)
		{
			tmp = head->next;
			ft_lstdelone(&head, del);
			head = tmp;
		}
		(*alst)->next = NULL;
		ft_lstdelone(alst, del);
	}
}
