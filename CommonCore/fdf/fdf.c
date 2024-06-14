/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:21:07 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/14 17:02:36 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_map *map;

    if (argc != 2)
    {
        ft_printf("Usage: fdf file\n");
        return (1);
    }
    map = parse_file(argv[1], create_map());
    if (!map)
    {
        ft_printf("Error: Could not parse file\n");
        return (1);
    }
    draw_map(map);
    return (0);
}
