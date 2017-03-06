/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:00:51 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/02 20:13:01 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tree(t_node *node)
{
	if (node->left)
		ft_print_tree(node->left);
	ft_putnbr(node->val);
	if (node->right)
		ft_print_tree(node->right);
}
