/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:51:04 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 14:26:24 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_extension_valid(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    if (i < 5)
        return (0);
    if (ft_strcmp(s + i - 4, ".fdf") != 0)
        return (0);
    return (1);
}
void	get_err(const char *err)
{
	size_t	i;

	i = 0;
	while (err[i])
	{
		write(2, &err[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}
int	open_file(char *file_name, int permissions)
{
	int	fd;

	fd = open(file_name, permissions);
	if (fd < 0)
		get_err(FILE_ERR);
	return (fd);
}

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*alloc_mem(size_t size, size_t size_of)
{
	void	*mem;

	mem = malloc (size * size_of);
	if (!mem)
		get_err(MALLOC_ERR);
	return (mem);
}
