/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:02 by emedeiro          #+#    #+#             */
/*   Updated: 2024/02/18 00:20:04 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_type(const char *specifier, va_list ap, int i)
{
	size_t	count;

	count = 0;
	if (specifier[i] == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (specifier[i] == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (specifier[i] == 'i' || specifier[i] == 'd')
		return (ft_print_base(va_arg(ap, int), 10, 's', count));
	if (specifier[i] == 'u')
		return (ft_print_base(va_arg(ap, unsigned int), 10, 's', count));
	if (specifier[i] == 'x')
		return (ft_print_base(va_arg(ap, unsigned int), 16, 'a', count));
	if (specifier[i] == 'X')
		return (ft_print_base(va_arg(ap, unsigned int), 16, 'A', count));
	if (specifier[i] == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long), 16, 'a', count));
	if (specifier[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_print_type(format, ap, i);
		}
		else
			count += write(1, &format[i], 1);
		++i;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	char	*oi;
	char	*ola = "o brendon esta muito calado";
	int	pois;

	pois = ft_printf("Meu: %s\n", oi);
	ft_printf("Meu caracteres: %d\n", pois);
	pois = printf("Del: %s\n", oi);
	printf("Dele caracteres: %d\n", pois);
}*/
