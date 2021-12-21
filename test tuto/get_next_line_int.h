/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:07:23 by nsar              #+#    #+#             */
/*   Updated: 2021/11/30 18:20:30 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_select(char *buf, int *ret);
char	*ft_select2(char *buf);
int		ft_check_return(int ret, char **str);
int		ft_check_error(int fd, char **line);
size_t	ft_strlen(const char *str);
int    get_next_line(int fd, char **line);
int		get_ret_value(int ret, int fd, char *buf);

#endif
