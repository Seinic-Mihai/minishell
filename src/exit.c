/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 14:07:16 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/03 13:31:39 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_nbr(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

static void		aux1(char **tmp, int *ex, int *ac)
{
	int	size;

	if (check_nbr(tmp[1]) == 1)
	{
		size = ft_atoi(tmp[1]);
		ft_putstr("exit\n");
		*ex = size;
		*ac = 42;
	}
	else
		ft_putstr_fd("exit: Expression Syntax.\n", 2);
}

void			aux(t_env *env, char *buff, int *ex, int *ac)
{
	char	**tmp;
	size_t	size;

	tmp = ft_strsplit(buff, ' ');
	if (tmp[0] != NULL && ft_strcmp("exit", tmp[0]) == 0)
	{
		size = ft_size(tmp);
		if (size > 2)
			ft_putstr_fd("exit: Expression Syntax.\n", 2);
		else if (size == 2)
			aux1(tmp, ex, ac);
		else if (size == 1)
		{
			ft_putstr("exit\n");
			*ac = 42;
		}
	}
	else
		env_preparation(buff, env);
	if (tmp != NULL)
		del_tab(tmp);
}
