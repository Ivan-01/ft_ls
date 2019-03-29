/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:07:08 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 15:27:29 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_node		*reading_dir(t_node *path, t_flags *flags, \
		DIR *dir, t_node *dir_list)
{
	struct stat		buf;
	char			*linkname;
	char			*tmp;
	struct dirent	*sd;

	while ((sd = readdir(dir)))
	{
		linkname = NULL;
		lstat(path->name, &buf);
		if ((buf.st_mode & S_IFLNK) != S_IFLNK || ((buf.st_mode & S_IFLNK) ==\
					S_IFLNK && flags->flag_l == 0))
		{
			tmp = ft_strjoin(path->name, "/");
			tmp = ft_update(tmp, ft_strjoin(tmp, sd->d_name));
			lstat(tmp, &buf);
			if (flags->flag_ca == 1 && ft_strcmp(sd->d_name, ".") && \
			ft_strcmp(sd->d_name, ".."))
				dir_list = node_add(dir_list, sd->d_name, buf);
			else if (flags->flag_a == 1 || sd->d_name[0] != '.')
				dir_list = node_add(dir_list, sd->d_name, buf);
			free(tmp);
		}
	}
	return (dir_list);
}

t_node				*only_dirs_fill(t_node *path, t_node *list)
{
	char			*tmp;
	t_node			*dir_list;

	dir_list = NULL;
	while (list)
	{
		if ((list->buf.st_mode & S_IFDIR) == S_IFDIR)
		{
			tmp = ft_strjoin(path->name, "/");
			tmp = ft_update(tmp, ft_strjoin(tmp, list->name));
			if (ft_strcmp(list->name, ".") && ft_strcmp(list->name, ".."))
				dir_list = node_add(dir_list, tmp, list->buf);
			free(tmp);
		}
		list = list->next;
	}
	return (dir_list);
}

void				count_dirs(t_node *path, t_flags *flags, DIR *dir, \
		int count_r)
{
	t_node			*dir_entity_list;
	t_node			*dir_names_list;

	dir_entity_list = NULL;
	dir_entity_list = reading_dir(path, flags, dir, dir_entity_list);
	dir_names_list = only_dirs_fill(path, dir_entity_list);
	display_entity(path, dir_entity_list, flags);
	flag_apply(dir_names_list, flags);
	if (flags->flag_cr == 1)
		display_dirs(dir_names_list, flags, ++count_r);
	ft_list_clean(&dir_entity_list);
	ft_list_clean(&dir_names_list);
}

void				display_dirs(t_node *path, t_flags *flags, int count_r)
{
	int				dirs_number;
	DIR				*dir;
	struct stat		buf;

	flags->entity_fill = 0;
	dirs_number = node_size(path);
	while (path)
	{
		dir = opendir(path->name);
		if ((dirs_number > 0 && ((path->buf.st_mode & S_IFDIR) == S_IFDIR || \
		((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->flag_l == 0)) \
					&& dir) || count_r > 0)
			ft_printf("\n") && ft_printf("%s:\n", path->name);
		if (!dir && !stat(path->name, &buf) && ((path->buf.st_mode & S_IFDIR) \
		== S_IFDIR || (((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->\
		flag_l == 0))) && (path->buf.st_mode & S_IFBLK) != S_IFBLK)
			ft_printf("ft_ls: %s: %s\n", path->name, strerror(errno));
		if (dir && ((path->buf.st_mode & S_IFDIR) == S_IFDIR || \
		((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->flag_l == 0)))
			count_dirs(path, flags, dir, count_r);
		if (dir)
			closedir(dir);
		path = path->next;
	}
}
