/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:01:50 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 00:08:34 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_map *map;
    t_fdf *fdf;

    if (!check_args(argc, argv))
        return (1);
    map = ft_data(argv[1]);
    if (!map)
        return (1);
    fdf = init_fdf(map);
    if (!fdf)
    {
        free_map(map);
        return (1);
    }
    render(map);
    mlx_loop(fdf->mlx);
    return (0);
}

int check_args(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr_fd("usage: fdf input_file\n", 2);
        return (0);
    }
    if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
    {
        ft_putstr_fd("Invalid file\n", 2);
        return (0);
    }
    return (1);
}
