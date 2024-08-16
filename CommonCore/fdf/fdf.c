/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:01:50 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/15 14:17:45 by emedeiro         ###   ########.fr       */
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
    print_map(fdf);
    render(fdf);
    
    return (0);
}

int check_args(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Usage: ./fdf <filename>");
        exit(EXIT_FAILURE);
    }
    if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
    {
        perror("Invalid file extension. Please use a .fdf file.");
        exit(EXIT_FAILURE);
    }
    perror("Invalid arguments. Please use only one file.");
    return (1);
}

void	print_map(t_fdf *fdf)
{
	int i;
    int j;
    
    i = 0;
    while (i < fdf->map->height)
    {
        j = 0;
        while (j < fdf->map->width)
        {
            printf(" %d ", fdf->map->matrix[i][j].z);
            j++;
        }
        printf("\n");
        i++;
    }
}