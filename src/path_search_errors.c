/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:22:37 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 15:21:30 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_node			*path_search_errors(t_node *path)
{
	t_node		*root;
	char		*str;

	path = node_sort_by_name(path, 0);
	root = path;
	while (path)
	{
		str = delete_slash(path->name);
		if (stat(path->name, &path->buf) && stat(str, &path->buf) && \
				lstat(path->name, &path->buf))
		{
			ft_printf("ft_ls: %s: ", path->name);
			perror("");
		}
		if (stat(path->name, &path->buf) && !stat(str, &path->buf) && \
				lstat(path->name, &path->buf))
		{
			ft_printf("ft_ls: %s: ", path->name);
			perror("");
		}
		free(str);
		path = path->next;
	}
	ft_list_clean(&path);
	return (root);
}
