/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:16:50 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/16 04:47:56 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#ifndef OPEN_MAX
# define OPEN_MAX 1024
# endif

char	*ftb_substr(const char *s, unsigned int start, size_t len);
char	*ftb_strjoin(char *s1, const char *s2);
char	*ftb_strchr(const char *s, int c);
char	*ftb_strdup(const char *s);
char	*get_next_line_bonus(int fd);

size_t	ftb_strlen(const char *s);

#endif
