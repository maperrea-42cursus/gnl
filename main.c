/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:08:00 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/28 13:33:23 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd1;
	int ret1;
	char *line;

	(void)argc;
	line = NULL;
	ret1 = 1;
	fd1 = open(argv[1], O_RDONLY);
	do {
		ret1 = get_next_line(fd1, &line);
		printf("%s : %d\n", line, ret1);
		free(line);
	} while (ret1);
	CHECK
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
