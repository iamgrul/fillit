/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_amount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:03:04 by shural            #+#    #+#             */
/*   Updated: 2018/01/12 19:20:39 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_vars_amount(t_list *lst, int sq_s)
{
	int		var;

	var = 0;
	while (lst)
	{
		var += (sq_s - (((char*)(lst->content))[7] - '0') + 1)
			* (sq_s - (((char*)(lst->content))[8] - '0') + 1);
		lst = lst->next;
	}
	return (var);
}
