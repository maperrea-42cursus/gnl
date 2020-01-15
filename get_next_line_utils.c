/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:26:05 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/15 20:00:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**ft_minisplit(char *str)
{
	char	(*strs)[2];
	int		l[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n' && j == 0)
			j++;
		else
			l[j]++;
		i++;
	}
	if (!(strs[0] = malloc(l[0] + 1)) || !(strs[1] = malloc(l[1] + 1)))
	   return (NULL);	
	i = 0;
	while (str[i] != '\n')
		strs[0][i] = str[i++];
	strs[0][i] = 0;
	j = 0;
	while (str[i - 1])
		strs[1][j++] = str[i++];
	return (strs);
}

void	ft_strrcat(char **str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*str1)[i])
		i++;
	while (str2[j])
		j++;
	ft_str_resize(str1, i + j + 1);
	j = 0;
	while (str2[j])
		(*str1)[i++] = str2[j++];
}

void	ft_str_resize(char **str, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = malloc(sizeof(char) * (size + 1))))
		return ;
	while ((*str)[i] && i < size)
		tmp[i] = (*str)[i++];
	tmp[i] = 0;
	free(*str);
	*str = tmp;
}

int		ft_lstadd_back(t_list **list, int fd, char *str)
{
	t_list new;

	if (!(new = malloc(sizeof(t_list))) || !(new->content = malloc(sizeof(t_file))))
		return 0;
	new->content->fd = fd;
	new->content->str = str;
	if (!(*list))
		(*list) = new;
	else
	{
		while ((*list)->next)
			list = &((*list)->next);
		(*list)->next = new;
	}
	return 1;
}

t_list	*ft_find_fd(t_list *list, int fd)
{
	while(list)
	{
		if (list->content->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}
