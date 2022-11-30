/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:22:53 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/30 21:24:59 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 10240
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