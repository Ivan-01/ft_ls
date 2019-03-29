/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:22:36 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 17:41:45 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node			*node_add(t_node *root, char *name, struct stat buf)
{
	t_node		*temp;
	t_node		*begin_list;

	if (root == NULL)
	{
		root = malloc(sizeof(t_node));
		root->name = ft_strdup(name);
		root->buf = buf;
		root->next = NULL;
		return (root);
	}
	begin_list = root;
	temp = (t_node *)malloc(sizeof(t_node));
	temp->name = ft_strdup(name);
	temp->buf = buf;
	temp->next = NULL;
	while (root->next)
		root = root->next;
	root->next = temp;
	return (begin_list);
}
