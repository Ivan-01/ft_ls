/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_apply_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:41:20 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/26 20:13:01 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node			*path_apply_flag(t_node *path, t_flags *flags)
{
	int			rev;

	rev = 0;
	if (flags->flag_r == 1)
		rev = 1;
	path = node_sort_by_name(path, rev);
	if (flags->flag_t == 1 && flags->flag_cs == 0)
		path = node_sort_by_time(path, rev);
	if (flags->flag_cs == 1)
		path = node_sort_by_size(path, rev);
	return (path);
}
