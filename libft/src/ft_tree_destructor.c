/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_destructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:57:28 by mseinic           #+#    #+#             */
/*   Updated: 2016/06/08 19:15:01 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_destructor(t_node *node)
{
	if (node != NULL)
	{
		ft_tree_destructor(node->left);
		ft_tree_destructor(node->right);
		free(node);
	}
}
