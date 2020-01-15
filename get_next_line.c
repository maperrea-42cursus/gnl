/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:25:57 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/15 20:00:10 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd)
{
	char	*line;
	char	buf[BUFFER_SIZE + 1];
	int		flag;
	int 	i;

	flag = 0;
	buf[BUFFER_SIZE] = 0;
	if (!(line = malloc(1)))
		return (NULL);
	*line = 0;
	while (!flag)
	{
		i = 0;
		read(fd, buf, BUFFER_SIZE);
		while (buf[i])
			if (buf[i++] = '\n')
				flag = 1;
		ft_strrcat(&line, buf);
	}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*file_list;
	t_list			*current_file;

	if (fd < 0)
		return (-1);
	if (!(current_file = ft_find_fd(file_list, fd)))
	{
		*line = ft_read_line(int fd);
		
	}
}
