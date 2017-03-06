/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:26:59 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/31 17:48:02 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_env(t_env *env, char **environ)
{
	size_t	size;
	char	*tmp;

	if ((size = 0) && environ != NULL)
	{
		while (environ[size++] != NULL)
			;
	}
	if (size == 0)
		size = 2;
	env->tab = NEW_TAB(sizeof(char *));
	if (t_tab_reserve(&env->tab, size))
		return ;
	size = 0;
	if (environ != NULL)
	{
		while (environ[size] != NULL)
		{
			tmp = ft_strdup(environ[size]);
			t_tab_add(&env->tab, &tmp, 1);
			size++;
		}
	}
}
