/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:42:58 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 12:40:53 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_get(char const *s1, char const *s2);
char	*ft_strchr_get(const char *string, int searchedChara);
void	ft_bzero_get(void *s, size_t n);
void	*ft_calloc_get(size_t elementCount, size_t elementSize);
size_t	ft_strlen_get(const char *theString);

#endif
