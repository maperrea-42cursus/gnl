/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:26:05 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/17 23:32:45 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_minisplit(char *str, char **strs)
{
	int		l[2];
	int		i;
	int		j;

	i = -1;
	j = 0;
	l[0] = 0;
	l[1] = 0;
	while (str[++i])
		str[i] == '\n' && j == 0 ? j++ : l[j]++;
	if (!(strs[0] = malloc(l[0] + 1)) ||
			!(strs[1] = malloc(l[1] + 1)))
		return ;
	i = -1;
	while (str[++i] != '\n' && str[i])
		strs[0][i] = str[i];
	strs[0][i++] = 0;
	j = 0;
	while (str[i - 1])
		strs[1][j++] = str[i++];
}

char	*ft_strrcat(char **str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*str1 && (*str1)[i])
		i++;
	while (str2[j])
		j++;
	ft_str_resize(str1, i + j + 1);
	j = 0;
	while (str2[j])
		(*str1)[i++] = str2[j++];
	(*str1)[i] = 0;
	return (*str1);
}

void	ft_str_resize(char **str, size_t size)
{
	char	*tmp;
	size_t	i;

	i = -1;
	if (!(tmp = malloc(sizeof(char) * (size + 1))))
		return ;
	while (*str && (*str)[++i] && i < size)
		tmp[i] = (*str)[i];
	tmp[i] = 0;
	free(*str);
	*str = tmp;
}

int		ft_lstadd_back(t_list **list, int fd, char *str)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))) ||
			!(new->content = malloc(sizeof(t_file))))
		return (0);
	new->content->fd = fd;
	new->content->str = str;
	new->next = NULL;
	if (!(*list))
		(*list) = new;
	else
	{
		while ((*list)->next)
			list = &((*list)->next);
		(*list)->next = new;
	}
	return (1);
}

t_list	*ft_find_fd(t_list *list, int fd)
{
	while (list)
	{
		if (list->content->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}
