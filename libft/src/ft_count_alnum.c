/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_alnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:40:18 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/29 17:45:34 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_alnum(const char *str)
{
	size_t nb;

	nb = 0;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (ft_isalnum(*str))
				nb++;
			str++;
		}
	}
	return (nb);
}
