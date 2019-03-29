/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_only_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:15:56 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/28 12:10:44 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			display_only_args(t_node *path, t_flags *flags)
{
	t_node		*argument_list;
	t_node		*begin_list;

	begin_list = path;
	argument_list = NULL;
	while (path)
	{
		if (!stat(path->name, &path->buf))
		{
			lstat(path->name, &path->buf);
			argument_list = node_add(argument_list, path->name, path->buf);
		}
		path = path->next;
	}
	ft_list_clean(&path);
	path = begin_list;
	display_entity(path, argument_list, flags);
	ft_list_clean(&argument_list);
}
