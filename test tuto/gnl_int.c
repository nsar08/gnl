/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:36:35 by nsar              #+#    #+#             */
/*   Updated: 2021/12/07 12:17:15 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return(i);
}


char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int j;
	size_t len;

	if (s1)
		len = ft_strlen(s1);
	if(s2)
		len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len ++;
	}
	j = -1;
	while (s2 && s2[++j])
		str[len++] = s2[j];
	str[len] = '\0';
	return(str);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		   return ((char *)s);	
		s++;
	}
	if (!*s && !c)
		return((char *)s);
	return (NULL);
}

char *ft_select(char *buf, int *ret)
{
	int i;
	char *dest;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return(NULL);
	if (ft_strchr(buf, '\n') != 0)
		*ret = 1;
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char *ft_select2 (char *buf)
{
	int i;
	int j;
	char *dest;
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(*dest) * (ft_strlen(buf) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (buf && buf[i])
		dest[j++] = buf[++i];
	dest[j] = 0;
	return (dest);
}

int get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	static char *str = NULL;
	char *temp;

	ret = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || !line || BUFFER_SIZE <= 0)
		return(-1);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	*line = ft_select(str, &ret);
	temp = str;
	str = ft_select2(temp);
		free(temp);
	return (ret);
}

int main()
{
	int fd = open("coucou.txt", O_RDONLY);
	char *line = NULL;
	int ret = get_next_line(fd, &line);

	while (ret != 0)
	{
		printf("\n\nTour de boucle\n\n");
		printf("%s", line);
		ret = get_next_line(fd, &line);
	}
}
