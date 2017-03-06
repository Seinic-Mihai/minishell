/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 16:54:21 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/03 13:27:46 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ret_var_path(char **env)
{
	char	**tmp;
	size_t	i;
	int		stop;

	stop = 0;
	i = 0;
	while (stop == 0 && env[i] != NULL)
	{
		tmp = ft_strsplit(env[i], '=');
		if (ft_strcmp(tmp[0], "PATH") == 0)
			stop = 1;
		i++;
		del_tab(tmp);
	}
	return (env[i - 1] + 5);
}

void			get_path(t_env *env)
{
	char	*var_path;

	var_path = ret_var_path((char **)env->tab.data);
	env->paths = ft_strsplit(var_path, ':');
}

void			init(t_env *env, char **environ)
{
	char	*str;
	int		val;
	char	**tmp;
	char	*aux;

	val = 0;
	ft_bzero(env, sizeof(t_env));
	get_env(env, environ);
	tmp = (char **)env->tab.data;
	aux = tmp[find_position(tmp, "SHLVL")];
	if (aux == NULL)
	{
		set_value(env, "SHLVL", "-1");
		aux = tmp[find_position(tmp, "SHLVL")];
	}
	val = ft_atoi((ft_strchr(aux, '=') + 1));
	if (val == 2147483647 || val < 0)
		val = 0;
	val++;
	str = ft_itoa(val);
	set_value(env, "SHLVL", str);
	free(str);
}

static void		first_check(t_env *env, int *ex, int *ac)
{
	int		ret;
	char	*buff;

	ft_putstr("minishell $> ");
	get_path(env);
	if ((ret = get_next_line(0, &buff)) > 0)
	{
		aux(env, buff, ex, ac);
		free(buff);
	}
	else
	{
		ft_putstr("exit\n");
		*ac = 42;
	}
}

int				main(int ac, char **av, char **environ)
{
	t_env			env;
	int				ex;

	ex = 0;
	ac = 0;
	(void)av;
	init(&env, environ);
	while (ac != 42)
	{
		first_check(&env, &ex, &ac);
		del_tab(env.paths);
	}
	del_tab((char **)env.tab.data);
	return (ex);
}
