/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcesq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:19:59 by shural            #+#    #+#             */
/*   Updated: 2018/01/12 19:19:10 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static unsigned char	*ft_choose_term(unsigned char **matrix,
		unsigned char *solve, int cur)
{
	int				i;
	int				j;

	i = 0;
	if (solve)
		while (solve[i])
		{
			if (matrix[i][0] == matrix[cur][0])
				solve[i] = '0';
			else
			{
				j = 1;
				while (j < 5)
				{
					if (matrix[i][j] == matrix[cur][1] ||
					matrix[i][j] == matrix[cur][2] || matrix[i][j] ==
					matrix[cur][3] || matrix[i][j] == matrix[cur][4])
						solve[i] = '0';
					j++;
				}
			}
			i++;
		}
	solve[cur] = '1';
	return (solve);
}

static int				ft_double_inc(t_list *lst, int cur_term)
{
	t_list			*target;
	int				j;

	target = lst;
	j = 0;
	while (lst)
	{
		if (j++ < cur_term + 1)
			target = target->next;
		if (j > cur_term + 1)
			if (ft_strcmp((char*)target->content,
			(char*)lst->content) == 0 && lst != target)
				return (1);
		lst = lst->next;
	}
	return (0);
}

unsigned char			*ft_calcesq(t_list *lst, unsigned char **matrix,
		unsigned char *solve, int cur_term)
{
	unsigned char	*temp;
	int				i;

	i = 0;
	temp = NULL;
	while (matrix[i] && matrix[i][0] != cur_term + 'A')
		i++;
	i--;
	while (matrix[++i] && matrix[i][0] == cur_term + 'A')
		if (solve[i] == '1')
		{
			temp = (unsigned char*)ft_strdup((char*)solve);
			temp = ft_choose_term(matrix, temp, i);
			if (cur_term == ft_terms_amount(lst) - 1)
				break ;
			else if (!(temp = ft_calcesq(lst, matrix, temp, cur_term + 1)))
			{
				if (ft_double_inc(lst, cur_term))
					break ;
			}
			else
				break ;
		}
	free(solve);
	return (temp);
}
