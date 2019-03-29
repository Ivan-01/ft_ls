/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:41:11 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 16:27:15 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			check_for_links(t_node *path, DIR *dir, t_flags *flags)
{
	if ((path->buf.st_mode & S_IFLNK) == S_IFLNK && !dir && flags->flag_l == 0)
		ft_printf("%s\n", path->name);
}

t_node			*find_symlink(t_node *path, t_node *symlink_list)
{
	char		*str;
	char		*real_name;

	str = get_full_symlink(path->name, path->name);
	real_name = ft_strjoin(path->name, str);
	free(str);
	symlink_list = node_add(symlink_list, real_name, path->buf);
	free(real_name);
	return (symlink_list);
}

void			display_symlink(t_node **object_list, t_node *path, DIR *dir, \
		t_flags *flags)
{
	if ((path->buf.st_mode & S_IFLNK) != S_IFLNK || ((path->buf.st_mode & \
	S_IFLNK) == S_IFLNK && path->name[0] == '/' && flags->flag_l == 0) || \
	((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->flag_l == 0 && 	\
	!dir))
		if ((path->buf.st_mode & S_IFDIR) != S_IFDIR && !stat(path->name, \
		&path->buf))
			*object_list = node_add(*object_list, path->name, path->buf);
}

void			display_objects(t_node *path, t_flags *flags)
{
	t_node		*object_list;
	t_node		*begin_list;
	DIR			*dir;

	object_list = NULL;
	begin_list = path;
	flags->entity_fill = 1;
	while (path)
	{
		dir = opendir(path->name);
		display_symlink(&object_list, path, dir, flags);
		check_for_links(path, dir, flags);
		if ((path->buf.st_mode & S_IFBLK) == S_IFBLK)
			object_list = node_add(object_list, path->name, path->buf);
		if (lstat(path->name, &path->buf) != -1)
			if ((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->flag_l == 1)
				object_list = find_symlink(path, object_list);
		if (dir)
			closedir(dir);
		path = path->next;
	}
	ft_list_clean(&path);
	path = begin_list;
	display_entity(path, object_list, flags);
	ft_list_clean(&object_list);
}
