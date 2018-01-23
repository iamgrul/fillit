/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:06:21 by shural            #+#    #+#             */
/*   Updated: 2018/01/12 18:53:04 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_printmap(unsigned char **matrix, unsigned char *str, int sq_s)
{
	int				i;
	unsigned char	*res;

	res = (unsigned char*)ft_strnew(sq_s * sq_s);
	res = ft_memset(res, (unsigned char)'.', sq_s * sq_s);
	i = -1;
	while (matrix[++i])
	{
		if (str[i] == '1')
		{
			res[matrix[i][1]] = matrix[i][0];
			res[matrix[i][2]] = matrix[i][0];
			res[matrix[i][3]] = matrix[i][0];
			res[matrix[i][4]] = matrix[i][0];
		}
	}
	i = 0;
	while (i < sq_s * sq_s)
	{
		ft_putchar(res[i]);
		i++;
		if (i != 0 && (i % sq_s) == 0)
			ft_putchar('\n');
	}
	free(res);
}
