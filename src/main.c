/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:10:10 by ltesha            #+#    #+#             */
/*   Updated: 2019/07/25 10:35:20 by ltesha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		check_args(char *str)
{
	int len;
	int i;

	i = -1;
	if (str[0] < '0' || str[0] > '9')
		return (0);
	g_map.h = ft_atoi(str);
	if (g_map.h < 1)
		return (0);
	while (str[++i] >= '0' && str[i] <= '9')
		;
	g_map.e = str[i++];
	g_map.o = str[i++];
	g_map.f = str[i++];
	while (str[i] == ' ')
		++i;
	if (str[i] != '\n')
		return (0);
	if (check_str(str) == 0)
		return (0);
	return (1);
}

char	*read_file(char *name)
{
	char	*data;
	int		des;
	int		len;
	int		size;
	char	buf[BUF_SIZE + 1];

	des = open(name, O_RDONLY);
	if (des == -1)
		return (NULL);
	len = 0;
	data = (char *)malloc(sizeof(char) * 1);
	while ((size = read(des, buf, BUF_SIZE)))
	{
		buf[size] = '\0';
		data = ft_concat(data, buf, len, size);
		len = len + size;
	}
	des = close(des);
	if (des == -1)
		return (NULL);
	return (data);
}

int		find_index(int **arr, int i, int j)
{
	int		l;
	int		a;
	int		b;
	int		c;

	a = arr[i - 1][j];
	b = arr[i - 1][j - 1];
	c = arr[i][j - 1];
	l = b <= a ? b : a;
	l = c <= l ? c : l;
	return (l + 1);
}

void	conv(char *str, int **m, t_elem e)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == g_map.o)
			m[j + 1][k + 1] = 0;
		else if (str[i] == g_map.e)
			m[j + 1][k + 1] = find_index(m, j + 1, k + 1);
		if (m[j + 1][k + 1] > e.v || (m[j + 1][k + 1] == e.v &&
					(j + 1 < e.i || k + 1 < e.j)))
			check_val(m[j + 1][k + 1], j + 1, k + 1, &e);
		k++;
		if (str[i + 1] == '\n')
		{
			k = 0;
			++j;
			++i;
		}
	}
	print_table(str, e);
}

int		main(int argc, char **argv)
{
	int			i;
	t_elem		e;
	int			**m;
	int			des;
	char		*data;

	if (argc < 2)
	{
		if (read_stdin(&argc, &argv) == 0)
			write(2, "map error\n", 10);
	}
	i = 0;
	while (++i < argc)
	{
		data = read_file(argv[i]);
		if (solve(data) == 0)
			write(2, "map error\n", 10);
		if (i < argc - 1)
			ft_putchar('\n');
	}
	return (1);
}
