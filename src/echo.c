/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:21:15 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/01 18:05:41 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	options(char *cmd)
{
	if (ft_strcmp("\\\\n", cmd) == 0)
		ft_putstr("\n");
	else if (ft_strcmp("\\\\t", cmd) == 0)
		ft_putstr("\t");
	else if (ft_strcmp("\\\\a", cmd) == 0)
		ft_putstr("\a");
	else if (ft_strcmp("\\\\b", cmd) == 0)
		ft_putstr("\b");
	else if (ft_strcmp("\\\\f", cmd) == 0)
		ft_putstr("\f");
	else if (ft_strcmp("\\\\r", cmd) == 0)
		ft_putstr("\r");
	else if (ft_strcmp("\\\\v", cmd) == 0)
		ft_putstr("\v");
	else
		ft_putstr(cmd);
}

static int	print_var(t_env *env, char *cmd)
{
	char	**tmp;
	char	*aux;
	char	*str;

	tmp = (char**)env->tab.data;
	aux = tmp[find_position(tmp, cmd + 1)];
	if (aux == NULL)
	{
		ft_putstr_fd(cmd + 1, 2);
		ft_putstr_fd(": Undefined variable.", 2);
		return (-1);
	}
	else
	{
		str = ft_strchr(aux, '=') + 1;
		ft_putstr(str);
	}
	return (0);
}

void		my_echo(t_env *env, char **cmd)
{
	size_t	size;
	size_t	i;
	int		ret;

	ret = 0;
	size = ft_size(cmd);
	i = 0;
	if (size > 1)
	{
		i = 1;
		while (cmd[i] != NULL && ret != -1)
		{
			if (cmd[i][0] != '$')
				options(cmd[i]);
			else
				ret = print_var(env, cmd[i]);
			ft_putstr(" ");
			i++;
		}
	}
	ft_putstr("\n");
}
