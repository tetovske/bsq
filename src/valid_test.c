/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:13:52 by ltesha            #+#    #+#             */
/*   Updated: 2019/07/25 10:46:37 by ltesha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		solve(char *data)
{
	t_elem	e;
	int		**m;
	int		i;

	if (check_args(data) == 0)
		return (0);
	init_struct(&e);
	while (*(data++) != '\n')
		;
	m = create_matrix(data);
	if (!m)
		return (0);
	conv(data, m, e);
	i = -1;
	while (++i < g_map.h + 1)
		free(m[i]);
	free(m);
	return (1);
}

int		read_stdin(int *argc, char ***argv)
{
	char	buf[BUF_IN + 1];
	int		size;
	char	*in;
	int		len;

	len = 0;
	in = (char *)malloc(sizeof(char) * 1);
	while ((size = read(0, buf, BUF_IN)))
	{
		if (solve(buf) == 0)
			return (0);
	}
	return (1);
}

int		input_check(char *s)
{
	int		c;
	int		wc;

	c = 0;
	wc = 0;
	while (*s != '\0')
	{
		if (*s == g_map.e || *s == g_map.f || *s == g_map.o)
			c++;
		else if (*s == '\n' || *(s + 1) == '\0')
		{
			wc++;
			if (c != g_map.w)
				return (0);
			c = 0;
		}
		else if (*s != g_map.e && *s != g_map.f && *s != g_map.o)
			return (0);
		++s;
	}
	if (wc != g_map.h)
		return (0);
	return (1);
}
