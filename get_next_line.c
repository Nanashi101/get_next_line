/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:20:57 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/28 23:37:10 by jael-mor         ###   ########.fr       */
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
	int		count;
	
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!data)
		data = ft_strdup("");
	count = 1;
	while(count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0 && !data)
			return (free(buffer), NULL);
		else if (count == 0 && data[0] == '\0')
			break ;
		else if (count == -1 && data)
			return(data = free_all(data, buffer));
		buffer[count] = '\0';
		data = ft_join(data, buffer);
		if(ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return(data);
}

static char	*ft_get_line(char	*data)
{
	int		i;
	char	*s;

	i = 0;
	if (!ft_strchr(data, '\n'))
		return (data);
	while (data[i] && data[i] != '\n')
		i++;
	s = malloc (i + 1);
	ft_strlcpy(s, data, i + 2);
	if (s[0] == '\0')
		return (free(s), NULL);
	return (s);
}

static char	*rest_save(char	*data)
{
	int		i;
	char	*s;

	i = 0;
	if (!ft_strchr(data, '\n'))
		return (NULL);
		
	while (data[i] != '\n')
		i++;
	if (data[i] == '\0')
		return (free(data), NULL);
	i++;
	s = malloc((ft_strlen(data) - i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, data + i, ft_strlen(data) - i + 2);
	free(data);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	data = readfile(fd, data);
	if (!data)
		return (NULL);
	line = ft_get_line(data);
	data = rest_save(data);
	if (line[0] == '\0')
	{
		free_all (line,data);
		return(NULL);
	}
	return(line);
}

// int main()
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));

// }