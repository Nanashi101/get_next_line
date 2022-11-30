/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:21:50 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/30 21:23:29 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_join(char *data, char *buffer);
int		ft_strchr(char *s, char c);
char	*free_all(char *data, char *buffer);
char	*readfile(int fd, char *data);
char	*ft_get_line(char	*data);
char	*rest_save(char	*data);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif