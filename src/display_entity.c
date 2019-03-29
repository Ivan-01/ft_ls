/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:53:52 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 12:33:36 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		display_detail(t_node *entity, t_flags *flags)
{
	char				c;

	mode_select(entity->buf.st_mode, &c, entity->name);
	ft_printf("%s%c", CHWHITE, c);
	ft_printf("%s", mode_print(entity->buf.st_mode));
	ft_printf("%3i ", entity->buf.st_nlink);
	if (flags->flag_g == 0)
		ft_printf("%-6s  ", getpwuid(entity->buf.st_uid)->pw_name);
	ft_printf("%-12s", getgrgid(entity->buf.st_gid)->gr_name);
	ft_printf("%6lld ", entity->buf.st_size);
	if (flags->flag_ct == 0)
		ft_printf("%.12s ", ctime(&entity->buf.st_mtime) + 4);
	else
		ft_printf("%.20s ", ctime(&entity->buf.st_mtime) + 4);
}

void			option_for_entity(t_node *path, t_node *entity, t_flags *flags)
{
	char		*str;

	if (flags->flag_l == 1)
		display_detail(entity, flags);
	if (flags->flag_cg == 1)
		print_colorised(entity);
	else
		ft_printf("%s", entity->name);
	if ((entity->buf.st_mode & S_IFLNK) == S_IFLNK && flags->flag_l == 1)
	{
		str = ft_strnew(1);
		str = ft_update(str, get_full_symlink(entity->name, path->name));
		if (str[0] != '\0')
			ft_printf("%s%s", CHWHITE, str);
		else
			ft_printf("%s", CHWHITE);
		free(str);
	}
	ft_printf("%s\n", CHWHITE);
}

void			display_entity(t_node *path, t_node *entity, t_flags *flags)
{
	long long	blocks;

	if (entity == NULL || path == NULL)
		return ;
	blocks = count_blocks(entity);
	entity = flag_apply(entity, flags);
	if ((path->buf.st_mode & S_IFDIR) == S_IFDIR && flags->flag_l == 1 \
	&& flags->entity_fill == 0 && flags->flag_d == 0)
		ft_printf("total %lld\n", blocks);
	while (entity)
	{
		option_for_entity(path, entity, flags);
		entity = entity->next;
	}
}
