/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:56:59 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/28 14:58:47 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
			new->next = NULL;
		}
		else
		{
			new->content = (void *)ft_memalloc(sizeof(void *) * content_size);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
			new->next = NULL;
		}
		return (new);
	}
	return (NULL);
}
