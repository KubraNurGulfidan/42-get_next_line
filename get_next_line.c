/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:49:43 by kgulfida          #+#    #+#             */
/*   Updated: 2024/02/06 18:53:17 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*read_line(int fd, char *buffer, char *stack)
{
	int		read_byte;
	char	*temp;

	while (1)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (0);
		else if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		if (!stack)
			stack = ft_strdup("");
		temp = stack;
		stack = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stack);
}

char	*clean_stack(char *line)
{
	int		i;
	char	*dest;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	dest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (dest == NULL)
		return (NULL);
	if (dest[0] == '\0')
	{
		free(dest);
		dest = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	char		*buffer;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, stack);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	stack = clean_stack(line);
	return (line);
}

// int	main(void)
// {
// 	int fd = open("kubra.txt", O_RDWR, 0777);
// 	char *str;
// 	int i = 0;

// 	while (i < 9)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s",str);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	int fd = open("kubra.txt", O_CREAT | O_RDWR, 777);
// 	int fd1 = open("gulfidan.txt", O_CREAT | O_RDWR, 777);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// }