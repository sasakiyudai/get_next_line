/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syudai <syudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:41:13 by syudai            #+#    #+#             */
/*   Updated: 2020/11/15 15:31:22 by syudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define FD_MAX 8200

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
size_t	ft_strchr(char *s, char c);
void	ft_strcpy(char *s1, char *s2, size_t n);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2, ssize_t n1, ssize_t n2);
int		ft_put_line(char **line, char **save, char *buf);
int		get_next_line(int fd, char **line);

#endif
