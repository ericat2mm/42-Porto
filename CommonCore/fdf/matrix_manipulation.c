/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:18:51 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/14 00:46:55 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define COS_ALPHA 0.894427191 
#define SIN_ALPHA 0.4472135955
#define COS_BETA 0.70710678118
#define SIN_BETA 0.70710678118

double RM_x[3][3] = {
    {1, 0, 0},
    {0, COS_ALPHA, -SIN_ALPHA},
    {0, SIN_ALPHA, COS_ALPHA}
};

double RM_y[3][3] = {
    {COS_BETA, 0, SIN_BETA},
    {0, 1, 0},
    {-SIN_BETA, 0, COS_BETA}
};

void multiplication_of_matrix(double RM_x[3][3], double RM_y[3][3], double RM[3][3])
{
    int i, j, k;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            RM[i][j] = 0;
            for (k = 0; k < 3; k++)
                RM[i][j] += RM_x[i][k] * RM_y[k][j];
        }
}

void matrix_multiplication_by_point(t_point *point, double RM[3][3])
{
    int x = point->x, y = point->y, z = point->z;
    point->x = RM[0][0] * x + RM[0][1] * y + RM[0][2] * z;
    point->y = RM[1][0] * x + RM[1][1] * y + RM[1][2] * z;
    point->z = RM[2][0] * x + RM[2][1] * y + RM[2][2] * z;
}
