/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:03:24 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/01 16:01:19 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_msg(char *str)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" varriable do not exists in env.\n", 2);
	return (1);
}

static void	set_pwd(t_env *env, char *str)
{
	char	*tmp;
	size_t	size;
	char	**tab;
	char	*ptr;

	tab = (char **)env->tab.data;
	ptr = tab[find_position(tab, "PWD")];
	if (ptr == NULL && error_msg("PWD"))
		return ;
	size = ft_strlen(ptr);
	tmp = ft_strdup(ptr);
	set_value(env, "PWD", str);
	set_value(env, "OLDPWD", ft_strchr(tmp, '=') + 1);
	free(tmp);
}

static void	simple_cd(t_env *env, int *ret, char **cmd)
{
	char	pwd[PATH_MAX];
	char	npath[PATH_MAX];
	char	*e;

	e = getcwd(pwd, PATH_MAX);
	*ret = chdir(cmd[1]);
	if (*ret > -1)
	{
		if (e)
			set_value(env, "OLDPWD", pwd);
		e = getcwd(npath, PATH_MAX);
		if (e)
			set_value(env, "PWD", npath);
	}
}

static void	flags_tmp(t_env *env, int *ret, char **cmd)
{
	char	**tmp;
	char	*str;
	char	*aux;

	tmp = (char**)env->tab.data;
	if (!ft_strcmp(cmd[1], "~"))
	{
		aux = tmp[find_position(tmp, "HOME")];
		if (aux == NULL && error_msg("HOME"))
			return ;
		str = ft_strchr(aux, '=') + 1;
		if ((*ret = chdir(str)) == 0)
			set_pwd(env, str);
	}
	else if (!ft_strcmp(cmd[1], "-"))
	{
		aux = tmp[find_position(tmp, "OLDPWD")];
		if (aux == NULL && error_msg("OLDPWD"))
			return ;
		str = ft_strchr(aux, '=') + 1;
		if ((*ret = chdir(str)) == 0)
			set_pwd(env, str);
	}
	else
		simple_cd(env, ret, cmd);
}

void		my_cd(t_env *env, char **cmd)
{
	size_t		size;
	char		**tmp;
	char		*str;
	char		*aux;
	int			ret;

	tmp = (char**)env->tab.data;
	size = ft_size(cmd);
	ret = 0;
	if (size == 2)
		flags_tmp(env, &ret, cmd);
	else if (size == 1)
	{
		aux = tmp[find_position(tmp, "HOME")];
		if (aux == NULL && error_msg("HOME"))
			return ;
		str = ft_strchr(aux, '=') + 1;
		if ((ret = chdir(str)) == 0)
			set_pwd(env, str);
	}
	else
		ft_putstr_fd("cd: too many arguments\n", 2);
	if (ret == -1)
		ft_putstr_fd("cd: Permission denied or file do not exists\n", 2);
}
