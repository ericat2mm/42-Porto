/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:50:02 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/26 15:08:31 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"

//CLIENT
void	send_size(int pid, int size);
void	send_message(int pid, char *str, int len);

//SERVER
void	handler_message(int sig);
void	handler_signal(int sig);
char	*ft_printf_free(char *str);
char	*ft_create(int size);
#endif