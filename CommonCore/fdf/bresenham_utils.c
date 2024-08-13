/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:55:08 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 15:15:12 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//step one of the bresenham algorithm
//delta_x = x_b - x_a
//delta_y = y_b - y_a

float step_one(int *x_a, int *y_a, int *x_b, int *y_b)
{
    float delta_x;
    float delta_y;

    delta_x = *x_b - *x_a;
    delta_y = *y_b - *y_a;
    return (delta_x, delta_y);
}

//step two of the bresenham algorithm
//Pb = Δy/Bigger
//Pa = Δx/Bigger

int step_two(float dx, float dy, int max)
{
    float Pa;
    float Pb;
    
    max = ft_abs(dx), ft_abs(dy);
    Pa = dx / max;
    Pb = dy / max;
    return (max, Pa, Pb);
}