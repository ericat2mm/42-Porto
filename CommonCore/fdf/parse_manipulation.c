/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:17:20 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 00:35:00 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point **parse_map(char *file)
{
    t_point **matriz;
    int fd;
    char *line;
    int y;

    y = 0;
    line = NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        get_err(FILE_ERR);
    while(line == get_next_line(fd))
        y++;
    close(fd);
    matriz = (t_point **)malloc(sizeof(t_point *) * y);
    fd = open(file, O_RDONLY);
    y = 0;
    while (get_next_line(fd))
    {
        matriz[y] = (t_point *)malloc(sizeof(t_point) * ft_wordcount(line, ' '));
        parse_line(&matriz[y], line);
        y++;
    }
    close(fd);
    return (matriz);
}
void parse_line(t_point **matrix, char *line)
{
    char	**dots;
	int		x;
    int y;

	if (!line)
		get_err(INVALID_MAP_ERR);
	dots = ft_split(line, ' ');
	x = 0;
    y = 0;
	while (dots[x])
	{
		is_number_valid(dots[x]);
		matrix[y][x].z = ft_atoi(dots[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].color = get_color_from_line(*(dots + x));
        matrix[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	matrix[y][--x].is_last = 1;
}

//is_number_valid function
void is_number_valid(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!ft_isdigit(s[i]) && s[i] != '-')
            get_err(INVALID_MAP_ERR);
        i++;
    }
}