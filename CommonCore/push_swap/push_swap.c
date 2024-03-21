/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:09:42 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/18 16:05:55 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
    if (argc == 2)
		two_argcs_logic(argv);
    else if (argc > 2)
		more_argcs_logic(argc, argv);
    return (0);
}