/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_sort_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:59:40 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/26 20:08:39 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_node		*node_sort_by_name(t_node *root, int is_asc)
{
	t_node	*b;
	t_node	*s;

	b = root;
	while (b)
	{
		s = root;
		while (s->next)
		{
			if (is_asc ? ft_strcmp(s->name, s->next->name) < 0 :
					ft_strcmp(s->name, s->next->name) > 0)
				node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	free(b);
	return (root);
}
