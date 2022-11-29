/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:21:50 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/29 20:41:02 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <libc.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_join(char *data, char *buffer);
int	ft_strchr(char *s, char c);

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);



#endif