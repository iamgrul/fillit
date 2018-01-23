/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defmatr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:04:25 by shural            #+#    #+#             */
/*   Updated: 2018/01/12 19:02:07 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static unsigned char		*ft_supfunc(t_list *lst, int sq_s, int r, int c)
{
	unsigned char	*res;

	res = (unsigned char*)ft_strnew(5);
	res[1] = r * sq_s + c + (((char*)(lst->content))[0] - '0');
	res[2] = r * sq_s + c + (((char*)(lst->content))[0] - '0')
		+ (((char*)(lst->content))[1] - '0') * sq_s
		+ (((char*)(lst->content))[2] - '0');
	res[3] = r * sq_s + c + (((char*)(lst->content))[0] - '0')
		+ (((char*)(lst->content))[3] - '0') * sq_s
		+ (((char*)(lst->content))[4] - '0');
	res[4] = r * sq_s + c + (((char*)(lst->content))[0] - '0')
		+ (((char*)(lst->content))[5] - '0') * sq_s
		+ (((char*)(lst->content))[6] - '0');
	return (res);
}

unsigned char				**ft_defmatr(t_list *lst, int sq_s)
{
	unsigned char	**res;
	int				cur_term;
	int				i;
	int				r;
	int				c;

	i = 0;
	cur_term = 0;
	res = ft_memalloc(sizeof(unsigned char*) * (ft_vars_amount(lst, sq_s) + 1));
	while (lst)
	{
		r = -1;
		while (++r < sq_s - (((char*)(lst->content))[7] - '0') + 1)
		{
			c = -1;
			while (++c < sq_s - (((char*)(lst->content))[8] - '0') + 1)
			{
				res[i] = ft_supfunc(lst, sq_s, r, c);
				res[i++][0] = cur_term + 'A';
			}
		}
		cur_term++;
		lst = lst->next;
	}
	return (res);
}
