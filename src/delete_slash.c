/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:34:00 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/21 16:10:08 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char			*delete_slash(char *str)
{
	int			i;
	char		*new;

	i = 0;
	if (str[ft_strlen(str) - 1] != '/')
	{
		new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		while (i < (int)ft_strlen(str) - 1)
		{
			new[i] = str[i];
			++i;
		}
		new[i] = '\0';
		return (new);
	}
	new = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (i < (int)ft_strlen(str) - 1)
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
