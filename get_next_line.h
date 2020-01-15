/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:40 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/15 20:00:13 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	t_file	*content;
	t_list	*next;
}				t_list;

typedef struct	s_file
{
	int		fd;
	char	*str;
}				t_file;

int				get_next_line(int fd, char **line);

void			ft_str_resize(char **str, size_t size);
void			ft_lstadd_back(t_list **list, int fd, char *str);
t_list			*ft_find_fd(t_list *list, int fd);

#endif
