/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:18:36 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/14 17:01:37 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point *create_point(int x, int y, char *line)
{
    t_point *point;

    point = (t_point *)malloc(sizeof(t_point));
    if (!point)
        return (NULL);
    point->x = x;
    point->y = y;
    point->z = ft_atoi(line);
    point->color = 0xFFFFFF;
    point->next = NULL;
    return (point);
}

static void add_point(t_point **list, t_point *new_point)
{
    t_point *current;

    if (!*list)
        *list = new_point;
    else
    {
        current = *list;
        while (current->next)
            current = current->next;
        current->next = new_point;
    }
}

void read_lines(int fd, t_map *map)
{
    char *line;
    int y = 0;
    int x;

    line = NULL;
    while (get_next_line(fd) > 0)
    {
        x = 0;
        while (line[x])
        {
            t_point *point = create_point(x, y, &line[x]);
            if (point)
                add_point(&(map->point), point);
            while (line[x] && line[x] != ' ')
                x++;
            while (line[x] == ' ')
                x++;
        }
        y++;
        free(line);
    }
    map->height = y;
}

t_map *parse_file(char *filename, t_map *map)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    read_lines(fd, map);
    close(fd);
    return (map);
}
