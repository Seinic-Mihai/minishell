/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:16:14 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 13:00:52 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t n;

	n = ft_strlen(s2);
	if (n == 0)
		return ((char *)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, n) == 0)
			return ((char *)s1);
		s1++;
	}
	return (0);
}
