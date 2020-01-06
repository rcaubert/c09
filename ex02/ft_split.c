/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:48:30 by raubert           #+#    #+#             */
/*   Updated: 2019/08/21 20:22:33 by raubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_checkcharset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while ((ft_checkcharset(charset, str[i]) == 1) && (str[i] != '\0'))
		{
			if (str[i + 1] == '\0')
				return (count);
			i++;
		}
		while ((ft_checkcharset(charset, str[i]) == 0) && (str[i] != '\0'))
			i++;
		count++;
	}
	return (count);
}

void	ft_decoup(char *dest, char *src, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	src = src + i;
}

char	**ft_split(char *str, char *charset)
{
	int		j;
	int		i;
	char	**tab;
	int		count;

	j = 0;
	i = 0;
	count = ft_count(str, charset);
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (0);
	while (j < count)
	{
		while ((ft_checkcharset(charset, str[i]) == 1) && (str[i] != '\0'))
			i++;
		str = str + i;
		i = 0;
		while ((ft_checkcharset(charset, str[i]) == 0) && (str[i] != '\0'))
			i++;
		if (!(tab[j] = malloc(sizeof(char) * (i + 1))))
			return (0);
		ft_decoup(tab[j], str, i);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
