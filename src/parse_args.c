/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:59:15 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 15:19:32 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node			*parse_args(int argc, char **argv, t_flags *flags)
{
	int			i;
	int			read;
	t_node		*path;
	struct stat	buf;

	i = 0;
	read = 0;
	path = NULL;
	while (++i < argc)
	{
		if (!read && argv[i][0] == '-' && ft_strcmp(argv[i], "--"))
			flag_set(&argv[i][1], flags);
		if (read || argv[i][0] != '-' || ft_strcmp(argv[i], "-") == 0)
		{
			read = 1;
			lstat(argv[i], &buf);
			path = node_add(path, argv[i], buf);
		}
	}
	if (!read)
	{
		lstat(".", &buf);
		path = node_add(path, ".", buf);
	}
	return (path);
}
