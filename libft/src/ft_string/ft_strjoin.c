/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:38:18 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/03 15:17:59 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n1;
	size_t	n2;

	n1 = 0;
	n2 = 0;
	if (s1 != NULL)
		n1 = ft_strlen(s1);
	if (s1 != NULL)
		n2 = ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(n1 + n2 + 1)))
		return (0);
	ft_memcpy(str, s1, n1);
	ft_memcpy(str + n1, s2, n2);
	str[n1 + n2] = '\0';
	return (str);
}
