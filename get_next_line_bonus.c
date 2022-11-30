/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:20:31 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/30 21:24:00 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_all(char *data, char *buffer)
{
	free(data);
	free(buffer);
	return (NULL);
}

char	*readfile(int fd, char *data)
{
	char	*buffer;
	ssize_t	count;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!data)
		data = ft_strdup("");
	count = 1;
	while (ft_strchr (data, '\n') == -1 && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1 && data)
			return (free_all(data, buffer));
		else if (count <= 0 && !data[0])
			return (free_all(data, buffer));
		else if (count == 0 && data)
			break ;
		buffer[count] = '\0';
		data = ft_join(data, buffer);
		if (!data)
			return (NULL);
	}
	free(buffer);
	return (data);
}

char	*ft_get_line(char	*data)
{
	int		i;
	char	*s;

	i = ft_strchr(data, '\n');
	if (i == -1)
		return (data);
	else
	{
		s = malloc ((i + 2) * sizeof(char));
		if (!s)
			return (NULL);
		ft_strlcpy(s, data, i + 2);
	}
	return (s);
}

char	*rest_save(char	*data)
{
	int		i;
	char	*s;

	i = ft_strchr(data, '\n');
	if (i == -1)
		return (NULL);
	else
	{	
		s = malloc((ft_strlen(data) - i + 1) * sizeof(char));
		if (!s)
			return (NULL);
		i++;
		ft_strlcpy(s, data + i, ft_strlen(data) - i + 2);
		free(data);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*data[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data[fd] = readfile(fd, data[fd]);
	if (!data[fd])
		return (NULL);
	line = ft_get_line(data[fd]);
	data[fd] = rest_save(data[fd]);
	return (line);
}

// int main()
// {
// 	int fd1 = open("test.txt",O_RDONLY);
// 	int fd2 = open("testt.txt",O_RDONLY);
// 	int fd3 = open("testtt.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd3));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd3));
// }