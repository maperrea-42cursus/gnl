/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:40 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/17 23:02:09 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list
{
	struct s_file	*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_file
{
	int		fd;
	char	*str;
}				t_file;

t_list			*ft_find_fd(t_list *list, int fd);
int				ft_find_nl(char *str);
char			*ft_read_line(int fd, t_list **list);
int				get_next_line(int fd, char **line);

void			ft_minisplit(char *str, char **strs);
char			*ft_strrcat(char **str1, char *str2);
void			ft_str_resize(char **str, size_t size);
int				ft_lstadd_back(t_list **list, int fd, char *str);
void			ft_remove_list_fd(t_list **list, int fd);

#endif
