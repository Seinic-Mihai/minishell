/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 18:45:58 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/24 10:24:27 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int negativ;
	int rez;

	negativ = 0;
	rez = 0;
	while ((*str == ' ' || *str == '\n' || *str == '\t')
			|| (*str == '\f' || *str == '\r' || *str == '\v'))
		str++;
	if (*str == '-')
		negativ = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		rez = (rez * 10) + (*str - 48);
		str++;
	}
	if (negativ)
		return (-rez);
	else
		return (rez);
}
