/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:15:42 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/18 12:39:37 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_err(char *err)
{
    ft_putendl_fd(err, 2);
    exit(EXIT_FAILURE);
}

int		is_extension_valid(char *file)
{
    int		i;
    
    i = ft_strlen(file);
    if (i < 4)
        return (0);
    if (file[i - 1] == 'f' && file[i - 2] == 'd' && file[i - 3] == 'f' && file[i - 4] == '.')
        return (1);
    return (0);
}

