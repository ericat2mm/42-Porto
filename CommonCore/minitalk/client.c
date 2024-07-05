/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:21:43 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/26 15:08:56 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/ft_printf.h"

int	main(int argc, char **argv)
{
	int			pid;
	char		*str;
	int			len;

	if (argc != 3)
	{
		ft_printf("ERROR\n./client <PID number> <message>\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	send_size(pid, len);
	send_message(pid, str, len);
	return (0);
}

void	send_size(int pid, int size)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (size & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	send_message(int pid, char *str, int size)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (i < size)
	{
		x = 8;
		while (x > 0)
		{
			if (str[i] & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			str[i] = str[i] << 1;
			x--;
			usleep(50);
		}
		i++;
	}
}
