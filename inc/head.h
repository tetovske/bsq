/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:12:05 by ltesha            #+#    #+#             */
/*   Updated: 2019/07/25 10:33:18 by ltesha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# define BUF_SIZE 8000
# define BUF_IN 1024
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_map
{
	int			h;
	int			w;
	char		e;
	char		o;
	char		f;
}				t_map;

typedef struct	s_elem
{
	int			i;
	int			j;
	int			v;
}				t_elem;

t_map			g_map;

char			*ft_realloc(char *str, int len);
void			ft_putstr(char *s);
void			ft_putchar(char c);
int				ft_atoi(char *s);
int				**create_matrix(char *str);
void			check_val(int value, int i, int j, t_elem *elem);
void			init_struct(t_elem *elem);
char			*ft_concat(char *str, char *s, int flen, int slen);
void			print_table(char *str, t_elem elem);
int				check_str(char *s);
int				input_check(char *s);
int				solve(char *data);
int				check_args(char *str);
void			conv(char *str, int **m, t_elem e);
int				read_stdin(int *argc, char ***argv);
void			parse(char *s);
char			*str_cpy(char *str, int from, int to);
char			*read_file(char *name);

#endif
