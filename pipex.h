/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:43:04 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/04 17:18:12 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

void	ft_exit(void);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
size_t	ft_strlen(char const *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_here_doc(char *delimiter);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_redirecting(char *file_name);
char	*ft_command_path(char *command);
char	**ft_split(const char *s, char c);
char	*ft_execute(char **lst, char **env);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_isfile(char *path, int check_dir, int check_permision);
void	ft_process_command(char **files, char *cmd, char **env, int trunc);

#endif
