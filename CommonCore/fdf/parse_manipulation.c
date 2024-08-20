/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:50:48 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 16:23:10 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point **parse_map(char *file_name)
{
    t_point	**matrix;
	int		y;
	int		fd;
	char	*line;

    matrix = allocate_dots(file_name);
    fd = open_file(file_name, O_RDONLY);
    y = 0;
    line = get_next_line(fd);
    if (!line)
    {
        free(matrix);
        get_err(INVALID_MAP_ERR);
    }
    while (line)
    {
        get_dots(line, matrix, y++);
        free(line);
        line = get_next_line(fd);
    }
    if (matrix[y])
        free(matrix[y]);
    matrix[y] = NULL;
    close(fd);
    return matrix;
}


t_point	**allocate_dots(char *file_name)
{
	t_point    **matrix;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open_file(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		get_err(INVALID_MAP_ERR);
	x = ft_wdcounter(line, ' ');
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	matrix = create_malloc_matrix(y, x);
	return (matrix);
}
int	get_dots(char *line, t_point **matrix, int y)
{
	char	**dots;
	int		x;

	if (!line)
		get_err(INVALID_MAP_ERR);
	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		is_number_valid(dots[x]);
		matrix[y][x].z = ft_atoi(dots[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].color = get_color_line(*(dots + x));
		matrix[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	matrix[y][--x].is_last = 1;
	return (x);
}
void	is_number_valid(char *s)
{
	int	i;

	if (!s)
		get_err(INVALID_MAP_ERR);
	i = 0;
	i += (s[i] == '-'); //if s[i] == '-' incrementa i
	while (s[i] && s[i] != ',')
	{
		if (!(ft_isdigit(s[i]) == 1 || ft_isdigit(s[i]) == 2) && (s[i] != ' ' || s[i] != '\t' \
            || s[i] != '\v' || s[i] != '\f' || s[i] != '\r'))
			get_err(INVALID_MAP_ERR);
		i++;
	}
	
	if (!s[i] || s[i] == ' ' || s[i] == '\n')
		return ;
	i += 1;
	if (ft_strlen(s + i) < 3) //3 -> minimo de uma cor hexagdecimal
		get_err(INVALID_MAP_ERR);
	while (s[i])
	{
		if (!in_string("0123456789abcdef", to_lower(s[i])))
			get_err(INVALID_MAP_ERR);
		i++;
	}
}
int	ft_wdcounter(char const *s, char c)
{
    int	i;
    int	count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    return (count);
}