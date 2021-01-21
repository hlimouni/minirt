/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:51:59 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/02 19:35:25 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free_null(char **str, int r)
{
	free(*str);
	*str = NULL;
	return (r);
}

static int	ft_read_and_store(char **str, char **end, int *ret, int fd)
{
	char	*buff;
	char	*tmp;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ft_free_null(str, -1));
	while (!(*end = ft_strchr(*str, '\n')) &&
										(*ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[*ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buff)))
		{
			free(buff);
			return (ft_free_null(str, -1));
		}
		free(*str);
		*str = tmp;
	}
	free(buff);
	return (1);
}

static int	ft_fill_line(char *end, char **str, char **line, int ret)
{
	if (!end || (**str == '\0' && ret == 0))
	{
		if (!(*line = ft_strdup(*str)) || ret < 0)
			return (ft_free_null(str, -1));
		return (ft_free_null(str, 0));
	}
	if (!(*line = ft_substr(*str, 0, end - *str)))
		return (ft_free_null(str, -1));
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char *str;
	int			ret;
	char		*tmp;
	char		*end;

	if (fd < 0 || read(fd, NULL, 0) || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!str)
	{
		if (!(str = ft_strdup("")))
			return (-1);
	}
	if (ft_read_and_store(&str, &end, &ret, fd) < 0)
		return (-1);
	if ((ret = ft_fill_line(end, &str, line, ret)) <= 0)
		return (ret);
	if (!(tmp = ft_strdup(end + 1)))
		return (-1);
	free(str);
	str = tmp;
	return (1);
}
