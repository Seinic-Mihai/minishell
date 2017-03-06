/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:06:18 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/03 16:30:40 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static const char	*ft_to_skip(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (str + i);
}

static const char	*ft_end_of_skip(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return ((str + i) - 1);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	char const	*aux;
	int			nb_words;

	nb_words = 0;
	aux = s;
	while ((aux = ft_to_skip(aux, c)) != NULL)
	{
		aux = ft_end_of_skip(aux, c) + 1;
		nb_words++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	tab[nb_words] = NULL;
	nb_words = 0;
	while ((s = ft_to_skip(s, c)) != NULL)
	{
		aux = s;
		s = ft_end_of_skip(s, c) + 1;
		tab[nb_words++] = ft_strsub(aux, 0, s - aux);
	}
	return (tab);
}
