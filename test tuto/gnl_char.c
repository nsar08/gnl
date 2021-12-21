/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:36:35 by nsar              #+#    #+#             */
/*   Updated: 2021/12/07 12:16:58 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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

char *ft_select(char *buf)
{
	int i;
	char *dest;

	i = 0;
	if (!buf[i])
		return(NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	dest = (char*)malloc(sizeof(char) * (i + 2));
	if (!dest)
		return(NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_select2 (char *buf)
{
	int i;
	int j;
	char *dest;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!dest)
		return(NULL);
	i++;
	j = 0;
	while (buf[i])
		dest[j++] = buf[i++];
	dest[j] = '\0';
	free(buf);
	return (dest);
}


char *ft_read_and_save(int fd, char *buf)
{
	char *buff;
	int ret;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return(NULL);
	ret = 1;
	while (!ft_strchr(buf, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return(NULL);
		}
		buff[ret] = '\0';
			buf = ft_strjoin(buf, buff);
	}
	free(buff);
	return (buf);
}
char  *get_next_line(int fd)
{
	char *line;	
	static char *buf;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(0);
	buf = ft_read_and_save(fd, buf);
	if(!buf)
		return(NULL);

	line = ft_select(buf);
	buf = ft_select2(buf);
	return (line);
}

int main(void)
{
	char *line;
	int fd;
	int i;

	fd = open("coucou.txt", O_RDONLY);
	i = 1;
	while(i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return(0);
}
