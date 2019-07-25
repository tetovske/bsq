/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:05:13 by ltesha            #+#    #+#             */
/*   Updated: 2019/07/25 11:05:47 by ltesha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	init_struct(t_elem *elem)
{
	extern t_map	g_map;

	elem->i = g_map.h + 1;
	elem->j = g_map.w + 1;
	elem->v = 0;
}

int		check_str(char *s)
{
	int				len;
	int				c;
	char			*f;
	extern t_map	g_map;

	len = 0;
	while (*s != '\n')
		++s;
	f = s + 1;
	while (*(++s) != '\n')
		len++;
	g_map.w = len;
	if (input_check(f) == 0)
		return (0);
	return (1);
}

void	print_table(char *str, t_elem e)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	while (str[++k] != '\0')
	{
		if (i >= e.i - e.v && i < e.i && j >= e.j - e.v && j < e.j)
			str[k] = g_map.f;
		++j;
		if (str[k + 1] == '\n')
		{
			j = 0;
			++k;
			++i;
		}
	}
	write(1, str, k);
}

int		**create_matrix(char *str)
{
	int				i;
	int				**m;
	extern t_map	g_map;

	i = -1;
	m = (int **)malloc(sizeof(int *) * (g_map.h + 1));
	while (++i < (g_map.h + 1))
		m[i] = (int *)malloc(sizeof(int) * (g_map.w + 1));
	i = -1;
	while (++i < (g_map.w + 1))
		m[0][i] = 0;
	i = -1;
	while (++i < (g_map.h + 1))
		m[i][0] = 0;
	return (m);
}

void	check_val(int value, int i, int j, t_elem *elem)
{
	elem->i = i;
	elem->j = j;
	elem->v = value;
}
