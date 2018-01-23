/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:30:30 by shural            #+#    #+#             */
/*   Updated: 2018/01/12 18:50:51 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst)
	{
		if (*alst)
		{
			temp = *alst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*alst = new;
	}
}
