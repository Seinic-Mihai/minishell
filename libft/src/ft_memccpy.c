/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:11:36 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/27 16:25:10 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char			*ptr1;
	const unsigned char		*ptr2;
	unsigned char			ch;

	ptr1 = (unsigned char *)d;
	ptr2 = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		if ((*ptr1++ = *ptr2++) == ch)
			return (ptr1);
	}
	return (0);
}
