/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:56:34 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 11:05:15 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main (int argc, char **argv)
{
    t_map   *map;
    t_fdf   *fdf;
    char   *read;
    
    if (!(check_args(argc,argv)))
        return (1);
    map = init_map();
    read = read_map(argv[1], map);
    if (!read)
        return (1);
    fdf = init_fdf(map);
    //render map
    render(fdf);
    //tecla para fechar a janela
    mlx_key_hook(fdf->win, key_hook, fdf);
    //mouse para rotacionar o mapa
    mlx_mouse_hook(fdf->win, mouse_hook, fdf);
    //loop para manter a janela aberta
    mlx_loop(fdf->mlx);
    free_map(map);
    free_fdf(fdf);
    return (0);
}

int check_args(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr_fd("usage: fdf input_file\n", 2);
        return (0);
    }
    if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) == 0)
    {
        ft_putstr_fd("Invalid file\n", 2);
        return (0);
    }
    return (1);
}