/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:34:27 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/04 17:19:51 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*ft_get_all(int fd)
{
	char	*s;
	char	*res;

	res = NULL;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		res = ft_strjoin(res, s);
	}
	return (res);
}

static void	ft_std(void)
{
	static int	status;

	if (!status)
	{
		status = dup(1);
	}
	else
	{
		close(1);
		dup2(status, 1);
		close(status);
		status = 0;
	}
}

char	*ft_execute(char **lst, char **env)
{
	int		fds[2];
	char	*res;
	pid_t	pid;

	pipe(fds);
	ft_std();
	dup2(fds[1], 1);
	close(fds[1]);
	pid = fork();
	if (!pid && execve(lst[0], lst, env))
	{
		perror("Execve failed");
		ft_exit();
	}
	wait(NULL);
	ft_std();
	res = ft_get_all(fds[0]);
	close(fds[0]);
	return (res);
}
