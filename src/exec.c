/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 15:16:53 by mseinic           #+#    #+#             */
/*   Updated: 2016/09/01 15:09:19 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		execute(char **exec_tab, char **env_tab)
{
	pid_t	pid;
	pid_t	status;
	int		ret;

	ret = 0;
	status = 0;
	if ((pid = fork()) == -1)
		error("fork error");
	if (pid == 0)
	{
		ret = execve(exec_tab[0], exec_tab, env_tab);
		if (ret == -1)
		{
			if (access(exec_tab[0], F_OK) != -1)
				ft_putstr_fd("minishell: permission denied: ", 2);
			else
				ft_putstr_fd("minishell: command not found: ", 2);
			ft_putstr_fd(exec_tab[0], 2);
			ft_putstr_fd("\n", 2);
			exit(-1);
		}
	}
	else
		wait(&status);
	return (ret);
}

int		bin_execute(char **tab, char **env, char *bin_path)
{
	char		str[1024];
	int			len;

	len = ft_strlen(tab[0]);
	ft_bzero(str, 1024);
	if (bin_path != NULL)
	{
		ft_strcat(str, bin_path);
		ft_strcat(str, "/");
	}
	ft_strcat(str, tab[0]);
	free(tab[0]);
	tab[0] = ft_strdup(str);
	execute(tab, env);
	return (0);
}
