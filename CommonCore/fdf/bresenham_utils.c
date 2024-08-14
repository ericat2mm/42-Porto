/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:55:08 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 18:01:35 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//step one of the bresenham algorithm
//delta_x = x_b - x_a
//delta_y = y_b - y_a

float step_one(t_point *p1, t_point *p2)
{
    float delta_x;
    
    delta_x = p2->x - p1->x;
    return (delta_x);
}

float step_one_two(t_point *p1, t_point *p2)
{
    float delta_y;

    delta_y = p2->y - p1->y;
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