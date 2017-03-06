/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:06:45 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/29 17:44:41 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *head;

	head = *alst;
	if (new != NULL && alst != NULL && *alst != NULL)
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}
