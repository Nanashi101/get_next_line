/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:20:57 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/29 21:10:47 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_all(char *data, char *buffer)
{
	free(data);
	free(buffer);
	return (NULL);
}

static char	*readfile(int fd, char *data)
{
	char	*buffer;
	ssize_t		count;
	
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!data)
		data = ft_strdup("");
	count = 1;
	while(ft_strchr(data, '\n') == -1 && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1 && data)
			return(free_all(data, buffer));
		else if (count <= 0 && !data[0])
			return (free_all(data, buffer));
		else if (count == 0 && data)
			break; 
		buffer[count] = '\0';
		data = ft_join(data, buffer);
		if (!data)
			return (NULL);
	}
	free(buffer);
	return(data);
}

static char	*ft_get_line(char	*data)
{
	int		i;
	char	*s;

	i = ft_strchr(data, '\n');
	if (i == -1)
		return (data);
	else
	{
		s = malloc ((i + 2) * sizeof(char));
		if(!s)
			return (NULL);
		ft_strlcpy(s, data, i + 2);
	// if (s[0] == '\0')
	// 	return (free(s), NULL);
	}
	return (s);
}

static char	*rest_save(char	*data)
{
	int		i;
	char	*s;

	i = ft_strchr(data, '\n');
	if (i == -1)
		return (NULL);
	else
	{	
	// while (data[i] != '\n')
	// 	i++;
	// if (data[i] == '\0')
	// 	return (free(data), NULL);
	// i++;
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
	static char	*data;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = readfile(fd, data);
	if (!data)
		return (NULL);
	line = ft_get_line(data);
	data = rest_save(data);
	// if (line[0] == '\0')
	// {
	// 	free_all (line,data);
	// 	return(NULL);
	// }
	return(line);
}

// int main()
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));

// }