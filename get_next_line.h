/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:54:53 by nsar              #+#    #+#             */
/*   Updated: 2021/12/11 18:21:05 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strjoin(char *save, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_select(char *save);
char	*ft_select2(char *save);
char	*ft_check_return(int ret, char **str);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
#endif
