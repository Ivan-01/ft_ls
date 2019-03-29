/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:43:20 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/27 16:29:48 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <time.h>
# include <unistd.h>
# include <uuid/uuid.h>
# include "../libft/libft.h"

# define CHRED		"\x1B[31m"
# define CHBLUE		"\x1B[34m"
# define CHPINK		"\x1B[35m"
# define CHWHITE	"\x1B[39m"
# define BXBLUE		"\x1B[46m"
# define BXYELLOW	"\x1B[43m"
# define BXBLACK	"\x1B[40m"

typedef struct		s_node
{
	char			*name;
	struct stat		buf;
	struct s_node	*next;
}					t_node;

typedef	struct		s_flags
{
	int				flag_a;
	int				flag_l;
	int				flag_t;
	int				flag_r;
	int				flag_g;
	int				flag_d;
	int				flag_ca;
	int				flag_cs;
	int				flag_ct;
	int				flag_cg;
	int				flag_cr;
	int				entity_fill;
	int				flag_illegal;
}					t_flags;

long long			count_blocks(t_node *entity);
char				*delete_slash(char *str);
void				display_only_args(t_node *path, t_flags *flags);
void				display_dirs(t_node *path, t_flags *flags, int count_r);
void				display_entity(t_node *path, t_node *entity, t_flags\
		*flags);
void				display_objects(t_node *path, t_flags *flags);
char				*get_full_symlink(char *link, char *path);
t_node				*parse_args(int argc, char **argv, t_flags *flags);
t_node				*path_apply_flag(t_node *path, t_flags *flag);
t_node				*path_search_errors(t_node *path);
void				print_colorised(t_node *entity);

t_node				*flag_apply(t_node *node_list, t_flags *flags);
void				flag_set(char *str, t_flags *flags);

char				*mode_print(mode_t mode);
void				mode_select(mode_t mode, char *c, char *name);

t_node				*node_add(t_node *root, char *name, struct stat buf);
void				node_copy(t_node *src, t_node *dst);
int					node_size(t_node *root);
t_node				*node_sort_by_name(t_node *roon, int is_asc);
t_node				*node_sort_by_size(t_node *info, int is_asc);
t_node				*node_sort_by_time(t_node *info, int is_asc);
void				node_swap(t_node *one, t_node *two);

void				ft_list_clean(t_node **list);
int					ft_str_find(char *s1, char *s2);

#endif
