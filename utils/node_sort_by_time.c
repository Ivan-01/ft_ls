/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_sort_by_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:21:44 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/26 20:09:19 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node			*node_sort_by_time(t_node *info, int is_asc)
{
	t_node		*b;
	t_node		*s;

	b = info;
	while (b)
	{
		s = info;
		while (s->next)
		{
			if (is_asc ? s->buf.st_mtime > s->next->buf.st_mtime :
					s->buf.st_mtime < s->next->buf.st_mtime)
				node_swap(s, s->next);
			if (s->buf.st_mtime == s->next->buf.st_mtime)
				if (is_asc ? s->buf.st_mtimespec.tv_nsec >
						s->next->buf.st_mtimespec.tv_nsec :
						s->buf.st_mtimespec.tv_nsec <
						s->next->buf.st_mtimespec.tv_nsec)
					node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	return (info);
}
