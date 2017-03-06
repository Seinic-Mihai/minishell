/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:20:44 by mseinic           #+#    #+#             */
/*   Updated: 2016/01/29 16:19:06 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *const save = dst;

	if (dst > src)
		while (len-- > 0)
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
	else if (dst < src)
		while (len-- > 0)
			*((unsigned char *)dst++) = *((unsigned char *)src++);
	return (save);
}
