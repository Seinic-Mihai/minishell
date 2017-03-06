/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:29:09 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/01 14:45:25 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_set_name(t_env *env)
{
	size_t i;

	i = 0;
	if (env->cmd_l[1][0] != '_' && !ft_isalpha(env->cmd_l[1][0]))
	{
		ft_putstr_fd("setenv: Variable name must begin with a letter.\n", 2);
		return (1);
	}
	while (env->cmd_l[1][i] != '\0')
	{
		if (env->cmd_l[1][i] != '_' && !ft_isalnum(env->cmd_l[1][i]))
		{
			ft_putstr_fd("setenv: Variable name must contain", 2);
			ft_putstr_fd(" alphanumeric characters.\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

size_t			find_position(char **env, char *key)
{
	size_t	i;
	char	**tmp;

	i = 0;
	while (env[i] != NULL)
	{
		tmp = ft_strsplit(env[i], '=');
		if (ft_strcmp(tmp[0], key) == 0)
		{
			del_tab(tmp);
			return (i);
		}
		del_tab(tmp);
		i++;
	}
	return (i);
}

static void		modif_value(t_env *env, char *key, char *value, size_t i)
{
	char	*tmp;
	size_t	size;
	char	**tab;

	tab = (char **)env->tab.data;
	size = ft_strlen(key) + ft_strlen(value) + 2;
	tmp = NULL;
	if (tab[i] != NULL)
		free(tab[i]);
	if ((tmp = (char *)malloc(sizeof(char) * size)) != NULL)
	{
		ft_bzero(tmp, size);
		ft_strcat(tmp, key);
		ft_strcat(tmp, "=");
		ft_strcat(tmp, value);
		tab[i] = ft_strdup(tmp);
		free(tmp);
	}
}

static void		set_new_value(t_env *env, char *key, char *value)
{
	char	*tmp;
	size_t	size;
	char	**tab;
	char	*null;

	tab = (char **)env->tab.data;
	size = ft_strlen(key) + ft_strlen(value) + 2;
	if ((tmp = (char *)malloc(sizeof(char) * size)) != NULL)
	{
		ft_bzero(tmp, size);
		ft_strcat(tmp, key);
		ft_strcat(tmp, "=");
		ft_strcat(tmp, value);
		t_tab_add(&env->tab, &tmp, 1);
		null = NULL;
		if (env->tab.size == env->tab.max_len)
			t_tab_add(&env->tab, &null, 1);
	}
}

void			set_value(t_env *env, char *key, char *value)
{
	size_t	i;

	i = 0;
	if ((i = find_position((char **)env->tab.data, key)) < env->tab.size)
		modif_value(env, key, value, i);
	else
		set_new_value(env, key, value);
}
