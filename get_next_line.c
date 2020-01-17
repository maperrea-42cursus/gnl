/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:25:57 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/17 23:29:42 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_find_nl(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_line(int fd)
{
	char	*line;
	char	*buf;
	int		flag;
	int		i;

	flag = BUFFER_SIZE;
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	line = NULL;
	while (flag == BUFFER_SIZE)
	{
		i = 0;
		flag = read(fd, buf, BUFFER_SIZE);
		buf[flag] = 0;
		while (buf[i])
			if (buf[i++] == '\n')
				flag = 1;
		ft_strrcat(&line, buf);
		if (*line == 0)
			flag = -2;
	}
	free(buf);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*file_list;
	t_list			*current_file;
	char			*tmp[2];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(current_file = ft_find_fd(file_list, fd)))
	{
		ft_minisplit(ft_read_line(fd), tmp);
		ft_lstadd_back(&file_list, fd, tmp[1]);
	}
	else
	{
		if (ft_find_nl(current_file->content->str))
			ft_minisplit(current_file->content->str, tmp);
		else
			ft_minisplit(ft_strrcat(&(current_file->content->str),
						ft_read_line(fd)), tmp);
		free(current_file->content->str);
		current_file->content->str = tmp[1];
	}
	*line = tmp[0];
	return (0);
}
