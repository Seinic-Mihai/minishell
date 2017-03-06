/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 20:30:45 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/03 15:15:45 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

# define NEW_TREE(type_size, cmp_fnc) (t_tree){NULL, type_size, 0, cmp_fnc}

typedef struct		s_node
{
	struct s_node	*up;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_tree
{
	t_node			*root;
	size_t			type_size;
	size_t			count;
	int				(*cmp)();
}					t_tree;

void				ft_add_node_to_tree(t_tree *tree, t_node *new_node);
#endif
