/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 18:45:04 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/30 15:49:50 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env_fnct(t_env *env, char *key)
{
	size_t	i;
	char	**tmp;
	char	*swap;

	tmp = (char **)env->tab.data;
	if ((i = find_position(tmp, key)) < env->tab.size)
	{
		swap = tmp[env->tab.size - 1];
		tmp[env->tab.size - 1] = tmp[i];
		tmp[i] = swap;
		free(tmp[env->tab.size - 1]);
		tmp[env->tab.size - 1] = NULL;
		env->tab.size--;
	}
}
