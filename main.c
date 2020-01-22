/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:08:00 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/21 20:46:50 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;
	int ret;
	char *line;

	(void)argc;
	line = NULL;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open("empty_file", O_RDONLY);
	fd4 = open("new_line", O_RDONLY);
	do {
		ret = get_next_line(fd1, &line);
		printf("%s\n", line);
	} while (ret);
/*	get_next_line(fd1, &line);
	printf("> %s\n", line);
	get_next_line(fd2, &line);
	printf("> %s\n", line);
	get_next_line(fd1, &line);
	printf("> %s\n", line);
	get_next_line(fd1, &line);
	printf("> %s\n", line);
	get_next_line(fd3, &line);
	printf("> empty file: %s\n", line);
	get_next_line(fd2, &line);
	printf("> %s\n", line); 
	get_next_line(fd4, &line);
	printf("> newline only: %s\n", line);
	get_next_line(fd2, &line);
	printf("> %s\n", line);
	get_next_line(fd2, &line);
	printf("> eof 2: %s\n", line);
	get_next_line(fd1, &line);
	printf("> eof 1: %s\n", line); 
	get_next_line(fd4, &line);
	printf("> eof nl: %s\n", line); */
}
