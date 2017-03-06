/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:47:12 by mseinic           #+#    #+#             */
/*   Updated: 2016/06/08 18:59:21 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_node_to_tree(t_tree *tree, t_node *new_node)
{
	t_node		**tmp;

	tmp = &tree->root;
	while (*tmp != NULL)
	{
		if (tree->cmp(*tmp, new_node) < 0)
			tmp = &(*tmp)->right;
		else
			tmp = &(*tmp)->left;
	}
	if ((*tmp = (t_node *)malloc(tree->type_size)) == NULL)
		return ;
	ft_memcpy(*tmp, new_node, tree->type_size);
	tree->count++;
}
