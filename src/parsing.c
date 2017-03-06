/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 13:26:12 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/01 18:00:45 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ret_access(char *path, char **bin_path)
{
	int		ret;
	char	str[1024];
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(path);
	ret = 0;
	if (bin_path != NULL)
	{
		while (bin_path[i] != NULL)
		{
			ft_bzero(str, 1024);
			ft_strcat(str, bin_path[i]);
			ft_strcat(str, "/");
			ft_strcat(str, path);
			if ((ret = access(str, 0)) == 0)
				break ;
			i++;
		}
	}
	if (ret == 0)
		return (i);
	return (ret);
}

static void		unset_env(t_env *env)
{
	size_t size;

	size = ft_size(env->cmd_l);
	if (size > 1)
	{
		size = 1;
		while (env->cmd_l[size] != NULL)
		{
			unset_env_fnct(env, env->cmd_l[size]);
			size++;
		}
	}
	else
		ft_putstr_fd("unsetenv: Too few arguments.\n", 2);
}

static void		set_env(t_env *env)
{
	size_t	size;
	size_t	i;

	size = ft_size(env->cmd_l);
	i = 0;
	if ((size == 2 || size == 3) && check_set_name(env))
		return ;
	if (size == 1)
		print_env(env, env->cmd_l);
	else if (size == 2)
		set_value(env, env->cmd_l[1], "");
	else if (size == 3)
		set_value(env, env->cmd_l[1], env->cmd_l[2]);
	else
		ft_putstr_fd("setenv: Too many arguments.\n", 2);
}

void			env_preparation(char *str, t_env *env)
{
	int		ret;

	ret = 0;
	env->cmd_l = ft_strsplit(str, ' ');
	if (env->cmd_l[0] != NULL)
	{
		if (ft_strcmp("env", env->cmd_l[0]) == 0)
			print_env(env, env->cmd_l);
		else if (ft_strcmp("echo", env->cmd_l[0]) == 0)
			my_echo(env, env->cmd_l);
		else if (ft_strcmp("cd", env->cmd_l[0]) == 0)
			my_cd(env, env->cmd_l);
		else if (ft_strcmp("setenv", env->cmd_l[0]) == 0)
			set_env(env);
		else if (ft_strcmp("unsetenv", env->cmd_l[0]) == 0)
			unset_env(env);
		else if (env->cmd_l[0][0] != '/' &&
				(ret = ret_access(env->cmd_l[0], env->paths)) >= 0)
			bin_execute(env->cmd_l, (char **)env->tab.data, env->paths[ret]);
		else
			ret = execute(env->cmd_l, (char **)env->tab.data);
	}
	del_tab(env->cmd_l);
}
