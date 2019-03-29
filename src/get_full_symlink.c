/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_symlink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:57:57 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 12:31:20 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char				*check_path_and_link(char *link, char *path)
{
	char		*temp;

	if (ft_strcmp(link, path) == 0)
		temp = ft_strjoin(path, "");
	else if (link[0] != '.' && link[0] != '/')
	{
		path = ft_strjoin(path, "/");
		temp = ft_strjoin(path, link);
		free(path);
	}
	else
		temp = ft_strjoin(path, "");
	return (temp);
}

char				*get_full_symlink(char *link, char *path)
{
	struct stat		buf;
	char			*linkname;
	ssize_t			r;
	char			*temp;

	if (ft_str_find(link, "->") == 1)
		return (ft_strdup(" "));
	temp = check_path_and_link(link, path);
	if (lstat(temp, &buf) != -1 && (linkname = malloc(buf.st_size + 1)) \
			!= NULL)
	{
		r = readlink(temp, linkname, buf.st_size + 5);
		if (r != -1)
		{
			linkname[r] = '\0';
			free(temp);
			temp = ft_strjoin(" -> ", linkname);
			free(linkname);
			return (temp);
		}
		free(linkname);
	}
	free(temp);
	return (ft_strdup(" "));
}
