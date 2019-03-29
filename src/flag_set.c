/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:11:21 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 15:18:17 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		next_set(char c, t_flags *flags)
{
	if (c == 'd')
		flags->flag_d = 1;
	else if (c == 'S')
		flags->flag_cs = 1;
	else if (c == 'T')
		flags->flag_ct = 1;
	else if (c == 'R')
		flags->flag_cr = 1;
	else if (c == 'G')
		flags->flag_cg = 1;
	else if (c == 'A')
		flags->flag_ca = 1;
	else
	{
		flags->flag_illegal = 1;
		ft_printf("ft_ls: illegal option -- %c\n", c);
		ft_printf("usage: ./ft_ls [AGRSTadglrt] [file ...]\n");
	}
}

void			flag_set(char *str, t_flags *flags)
{
	while (*str != '\0' && flags->flag_illegal == 0)
	{
		if (*str == 'l')
			flags->flag_l = 1;
		else if (*str == 'a')
			flags->flag_a = 1;
		else if (*str == 't')
			flags->flag_t = 1;
		else if (*str == 'r')
			flags->flag_r = 1;
		else if (*str == 'g')
		{
			flags->flag_l = 1;
			flags->flag_g = 1;
		}
		else
			next_set(*str, flags);
		str++;
	}
}
