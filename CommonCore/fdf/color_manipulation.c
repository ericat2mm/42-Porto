/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:25:20 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/18 11:29:00 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_color_from_line(char *s)
{
    int i;

    i = 0;
    while (s[i] && s[i] != ',')
        i++;
    if (!s[i])
        return (-1);
    return (ft_atoi_base(s + i + 2)); // +2 to skip the '0x'
}

int ft_atoi_base(char *s)
{
    char *base;
    int i;
    int res;

    base = "0123456789ABCDEF";
    i = 0;
    res = 0;
    while (s[i])
    {
        res = res * 16 + (ft_strchr(base, s[i]) - base);
        i++;
    }
    return (res);
}