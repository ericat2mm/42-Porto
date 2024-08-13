/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:55:08 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 20:43:50 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//step one of the bresenham algorithm
//delta_x = x_b - x_a
//delta_y = y_b - y_a

float step_one(float *x_a, float *x_b)
{
    float delta_x;

    delta_x = *x_b - *x_a;
    return (delta_x);
}

float step_one_two(float *y_a, float *y_b)
{
    float delta_y;

    delta_y = *y_b - *y_a;
    return (delta_y);
}

float step_two(float dx, float dy, float max)
{    
    if (dx > dy)
        max = dx;
    else
        max = dy;
    return (max);
}
float step_two_two(float dx, float max)
{
    float Pa;
    
    Pa = dx / max;
    return (Pa);
}
float step_two_three(float dy, float max)
{
    float Pb;
    
    Pb = dy / max;
    return (Pb);
}