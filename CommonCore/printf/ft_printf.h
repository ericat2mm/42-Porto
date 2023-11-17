/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:08:02 by emedeiro          #+#    #+#             */
/*   Updated: 2023/11/17 12:11:31 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *format, ...);
int ft_print_base(long int s, int n, char p, size_t count);
int ft_print_ptr(unsigned long long s, int n, char p, size_t count);
int ft_print_char(unsigned char s);
int ft_print_str(char *s);

#endif
