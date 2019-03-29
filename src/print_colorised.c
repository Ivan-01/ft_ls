/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colorised.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:59:31 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/28 12:06:45 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_link(char *link)
{
	ft_printf("%s", CHPINK);
	while (*link && *link != ' ')
		ft_printf("%c", *link++);
	ft_printf("%s", CHWHITE);
	if (*link == '\0')
		return ;
	ft_printf(" ");
	++link;
	while (*link)
		ft_printf("%c", *link++);
}

void		print_colorised(t_node *entity)
{
	if ((entity->buf.st_mode & S_IFBLK) == S_IFBLK)
		ft_printf("%s%s%s%s%s", CHBLUE, BXBLUE, entity->name, BXBLACK, CHWHITE);
	else if ((entity->buf.st_mode & S_IFLNK) == S_IFLNK)
		ft_print_link(entity->name);
	else if ((entity->buf.st_mode & S_IFDIR) == S_IFDIR)
		ft_printf("%s%s", CHBLUE, entity->name);
	else if ((entity->buf.st_mode & S_IXUSR) == S_IXUSR)
		ft_printf("%s%s", CHRED, entity->name);
	else if ((entity->buf.st_mode & S_IFCHR) == S_IFCHR)
		ft_printf("%s%s%s%s%s", CHBLUE, BXYELLOW, entity->name, BXBLACK,\
				CHWHITE);
	else
		ft_printf("%s%s", CHWHITE, entity->name);
}
