/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:34:05 by shural            #+#    #+#             */
/*   Updated: 2018/01/12 19:32:35 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static int			ft_termlstadd(t_list **list, char *str)
{
	int i;
	int x;

	i = 0;
	x = ft_strchr((const char *)str, '#') - str;
	while (i < 19)
	{
		if (str[x + 5 * (g_terms[i][1] - '0') + g_terms[i][2] - '0'] == '#' &&
		str[x + 5 * (g_terms[i][3] - '0') + g_terms[i][4] - '0'] == '#' &&
		str[x + 5 * (g_terms[i][5] - '0') + g_terms[i][6] - '0'] == '#')
		{
			ft_lstaddback(list, ft_lstnew(g_terms[i], 11));
			return (1);
		}
		i++;
	}
	return (0);
}

static int			ft_checkstr(char *str)
{
	int i;
	int tochki;
	int reshetki;

	i = 0;
	tochki = 0;
	reshetki = 0;
	while (i < 21)
	{
		if (str[i] == '.')
			tochki++;
		if (str[i] == '#')
			reshetki++;
		i++;
	}
	if (tochki == 12 && reshetki == 4)
		if (str[4] == '\n' && str[9] == '\n' && str[14] == '\n' &&
		str[19] == '\n')
			if (str[20] == '\n' || str[20] == '\0')
				return (1);
	return (0);
}

t_list				*ft_check(char *filename)
{
	int		fd;
	int		ret;
	int		lastret;
	char	buf[BUF_SIZE];
	t_list	*lst;

	lastret = 0;
	lst = NULL;
	if ((fd = open(filename, O_RDONLY)))
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			if (!((ret == 21 || ret == 20) && ft_checkstr(buf) &&
			ft_termlstadd(&lst, buf)))
				break ;
			ft_bzero(buf, 21);
			lastret = ret;
		}
		if (ret != 0 || lastret != 20)
			ft_lstdel(&lst, &ft_destr);
	}
	close(fd);
	return (lst);
}
