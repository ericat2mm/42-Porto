/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:59:29 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:50:33 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_key(int key)
{
	return (key == 'c' || key == 'o' || key == 'n' || \
			key == '-' || key == 'w' || key == 's' || \
			key == '1' || key == '4' || key == 22 || \
			key == 'a' || key == 'd' || \
			key == '6' || key == 'z' || key == 'x');
}
