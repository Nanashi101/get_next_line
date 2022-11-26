/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:27:14 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/26 22:11:05 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

 char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join(char *data, char *buffer)
{
	size_t	i;
	char	*new;

	if (!data || !buffer)
		return (0);
	new = (malloc(ft_strlen((char *)data) + ft_strlen((char *)buffer) + 1));
	if (!new)
		return (0);
	i = ft_strlen(data);
	ft_strlcpy(new, data, i + 1);
	ft_strlcpy(new + i, buffer, ft_strlen(buffer) + 1);
	free(data);
	return (new);
}

size_t	ft_strlcpy(char *dst,  char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s) + 1;
	while (i < size)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
