/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shural <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:38:17 by shural            #+#    #+#             */
/*   Updated: 2018/01/11 19:38:18 by shural           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "Libft/libft.h"

# define BUF_SIZE 21

static const char	g_terms[19][10] = {"010203041", "001020314", "001021023",\
	"010202132", "21/1.1023", "001112132", "010111223", "001102032",\
	"001021223", "1102/2032", "010011122", "1011/1023", "010112132",\
	"001111223", "1101/2/32", "1101/1123", "010112032", "001021123",\
	"1101/2032"};

void				ft_lstaddback(t_list **alst, t_list *new);
int					ft_sqrt(int num);
int					ft_terms_amount(t_list *lst);
int					ft_vars_amount(t_list *lst, int sq_s);
unsigned char		**ft_defmatr(t_list *lst, int sq_s);
t_list				*ft_check(char *filename);
void				ft_printmap(unsigned char **matrix, unsigned char *str,
					int sq_s);
void				ft_destr(void *cont, size_t len);
unsigned char		*ft_calcesq(t_list *lst, unsigned char **matrix,
					unsigned char *solve, int cur_term);

#endif
