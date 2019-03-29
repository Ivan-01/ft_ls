/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:11:20 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/26 20:07:07 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		node_swap(t_node *one, t_node *two)
{
	t_node *temp;

	temp = (t_node *)malloc(sizeof(t_node));
	node_copy(one, temp);
	node_copy(two, one);
	node_copy(temp, two);
	free(temp);
}
