/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:48:45 by mseinic           #+#    #+#             */
/*   Updated: 2016/01/29 17:13:50 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (*d)
		d++;
	while (*s)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}
