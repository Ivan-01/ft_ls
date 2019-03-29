/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:30:43 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/25 15:35:53 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

long long			count_blocks(t_node *entity)
{
	t_node			*tmp;
	long long		blocks;

	blocks = 0;
	tmp = entity;
	while (tmp)
	{
		blocks += tmp->buf.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}
