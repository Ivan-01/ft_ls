/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 09:23:33 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/26 15:50:21 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			mode_select(mode_t mode, char *c, char *name)
{
	if ((mode & S_IFDIR) == S_IFDIR)
		*c = 'd';
	if ((mode & S_IFCHR) == S_IFCHR)
		*c = 'c';
	if ((mode & S_IFIFO) == S_IFIFO)
		*c = 'p';
	if ((mode & S_IFBLK) == S_IFBLK)
		*c = 'b';
	if ((mode & S_IFSOCK) == S_IFSOCK)
		*c = 's';
	if ((mode & S_IFREG) == S_IFREG)
		*c = '-';
	if (ft_strchr(name, '>') || (mode & S_IFLNK) == S_IFLNK)
		*c = 'l';
}
