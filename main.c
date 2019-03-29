/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:34:11 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/28 12:04:53 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_node		*path;
	t_flags		flags;

	path = NULL;
	ft_bzero(&flags, sizeof(t_flags));
	path = parse_args(argc, argv, &flags);
	if (flags.flag_illegal == 1)
		return (0);
	path = path_search_errors(path);
	path = path_apply_flag(path, &flags);
	if (flags.flag_d == 1)
		display_only_args(path, &flags);
	else
	{
		display_objects(path, &flags);
		display_dirs(path, &flags, 0);
	}
	ft_list_clean(&path);
	return (0);
}
