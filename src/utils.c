/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:25:53 by ltesha            #+#    #+#             */
/*   Updated: 2019/07/25 10:43:38 by ltesha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
		ft_putchar(s[i]);
}

int		ft_atoi(char *s)
{
	int		k;
	int		num;

	k = 1;
	while (*s == ' ' || *s == '+')
		s++;
	if (*s == '-')
	{
		k = -1;
		++s;
	}
	num = 0;
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num * k);
}

char	*ft_concat(char *str, char *s, int flen, int slen)
{
	int		i;
	int		j;
	char	*ret;
	int		l;

	l = flen + slen + 1;
	ret = (char *)malloc(sizeof(char) * l);
	ret[l - 1] = '\0';
	i = -1;
	j = -1;
	while (++i < l)
	{
		if (i == flen)
			j = -1;
		if (i < flen)
			ret[i] = str[++j];
		else
			ret[i] = s[++j];
	}
	return (ret);
}
