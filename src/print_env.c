/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 13:22:38 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/01 18:04:25 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t		ft_size(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

static void	aux_exec(t_env *env, char **cmd, size_t k, size_t *size)
{
	size_t	i;
	int		ret;

	ret = 0;
	i = k;
	if (cmd[i] != NULL)
	{
		if (ft_strcmp("echo", cmd[i]) == 0)
			my_echo(env, cmd + i);
		else if (ft_strcmp("cd", cmd[i]) == 0)
			my_cd(env, cmd + i);
		else if (cmd[i][0] != '/' && env->paths != NULL &&
				(ret = ret_access(cmd[i], env->paths)) >= 0)
			bin_execute(cmd + i, (char **)env->tab.data, env->paths[ret]);
		else
			ret = execute(cmd + i, (char **)env->tab.data);
	}
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_putstr(cmd[i]);
		ft_putstr("\n");
	}
	*size = 1;
}

static void	get_tmp_set(t_env *tmp, char **cmd, size_t *size)
{
	size_t	i;
	char	*str;
	char	*chr;

	i = 1;
	if (ft_strcmp(cmd[1], "-i") == 0)
		i = 2;
	while (cmd[i] != NULL && ft_strchr(cmd[i], '=') != NULL)
	{
		str = ft_strdup(cmd[i]);
		chr = ft_strchr(str, '=');
		*chr = '\0';
		set_value(tmp, str, chr + 1);
		free(str);
		i++;
	}
	if (cmd[i] != NULL && *size != 1)
		aux_exec(tmp, cmd, i, size);
}

static void	aux_init(t_env *env, t_env *tmp, size_t *size, char **null)
{
	if (ft_strcmp(env->cmd_l[1], "-i") != 0)
	{
		init(tmp, (char **)env->tab.data);
		get_path(tmp);
	}
	else
	{
		init(tmp, (char **)null);
		unset_env_fnct(tmp, "SHLVL");
	}
	if (ft_strcmp(env->cmd_l[1], "-u") == 0 && env->cmd_l[2] != NULL)
	{
		unset_env_fnct(tmp, env->cmd_l[2]);
		get_path(tmp);
		if (env->cmd_l[3] != NULL)
			aux_exec(tmp, env->cmd_l, 3, size);
	}
}

void		print_env(t_env *env, char **cmd)
{
	t_env		tmp;
	char		*null[1];
	size_t		size;

	null[0] = NULL;
	size = ft_size(cmd);
	if (size > 1)
	{
		aux_init(env, &tmp, &size, null);
		if (ft_strcmp(cmd[1], "-u") != 0)
			get_tmp_set(&tmp, (char **)cmd, &size);
		if (size > 1)
			print_tab((char **)tmp.tab.data);
		if (tmp.paths != NULL)
			del_tab(tmp.paths);
		del_tab((char **)tmp.tab.data);
	}
	else
		print_tab((char **)env->tab.data);
}
