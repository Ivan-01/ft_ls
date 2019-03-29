/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:10:27 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 13:58:10 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_wide_str(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		++i;
	}
	return (i);
}