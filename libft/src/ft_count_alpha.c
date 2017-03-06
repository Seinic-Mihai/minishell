/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:56 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/29 17:53:25 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_alpha(const char *str)
{
	size_t	nb;

	nb = 0;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (ft_isalpha(*str))
				nb++;
			str++;
		}
	}
	return (nb);
}
