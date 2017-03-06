/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:58:53 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/29 17:45:15 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digit(const char *str)
{
	size_t nb;

	nb = 0;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (ft_isdigit(*str))
				nb++;
			str++;
		}
	}
	return (nb);
}
