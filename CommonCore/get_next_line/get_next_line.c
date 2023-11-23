/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:30 by emedeiro          #+#    #+#             */
/*   Updated: 2023/11/21 17:31:34 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;
	
	temp = ft_strjoin(buffer, buf);
	return (temp);
}

char	ft_next_line(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (line);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*ft_read_file(int fd, char res)
{
	char	*buffer;
	int	byte_read;
	
	if (!res)
		res = ft_calloc(1,1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (free(res), NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\0'))
			break;
	}
	free(buffer);
	return (res);
}

char	*ft_get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

int main (void)
{
	char *fixe;
        int fd;

        while ((fixe = get_next_line(fd)))
        {
              printf("%s", fixe);
              free(fixe);
	}
}
