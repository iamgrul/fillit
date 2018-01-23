/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:27:55 by shural            #+#    #+#             */
/*   Updated: 2018/01/12 19:25:26 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static void		ft_matrix_destr(unsigned char **matrix, int len)
{
	int				i;

	if (matrix)
	{
		i = 0;
		while (i < len)
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

static void		ft_main_cycle(t_list *lst, unsigned char **matrix,
		unsigned char *solve)
{
	int				sq_s;

	sq_s = ft_sqrt(ft_terms_amount(lst) * 4);
	while (!solve)
	{
		ft_matrix_destr(matrix, ft_vars_amount(lst, sq_s - 1) + 1);
		matrix = ft_defmatr(lst, sq_s);
		solve = (unsigned char*)ft_strnew(ft_vars_amount(lst, sq_s));
		solve = ft_memset(solve, '1', ft_vars_amount(lst, sq_s));
		solve = ft_calcesq(lst, matrix, solve, 0);
		sq_s++;
	}
	ft_printmap(matrix, solve, sq_s - 1);
	ft_matrix_destr(matrix, ft_vars_amount(lst, sq_s - 1) + 1);
	ft_lstdel(&lst, &ft_destr);
	if (solve)
		free(solve);
}

int				main(int argc, char **argv)
{
	t_list			*lst;
	unsigned char	**matrix;
	unsigned char	*solve;

	matrix = NULL;
	solve = NULL;
	lst = NULL;
	if (argc == 2)
	{
		lst = ft_check(argv[1]);
		if (lst)
			ft_main_cycle(lst, matrix, solve);
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit \"source_file\"");
	return (0);
}
