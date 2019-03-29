/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:03:00 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 15:23:08 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_node			*flag_apply(t_node *node_list, t_flags *flags)
{
	int			rev;

	rev = 0;
	if (flags->flag_r == 1)
		rev = 1;
	node_list = node_sort_by_name(node_list, rev);
	if (flags->flag_t == 1 && flags->flag_cs == 0)
		node_list = node_sort_by_time(node_list, rev);
	if (flags->flag_cs == 1)
		node_list = node_sort_by_size(node_list, rev);
	return (node_list);
}
