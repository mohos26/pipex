/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:12:44 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/04 12:24:40 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	**ft_create_lst(char *cmd)
{
	char	**lst;
	char	*aid;

	lst = ft_split(cmd, ' ');
	if (!lst)
	{
		if (!ft_strlen(cmd))
			ft_putendl_fd("cmd: empty", 2);
		else
			perror("allocation");
		exit(EXIT_FAILURE);
	}
	aid = ft_command_path(*lst);
	free(*lst);
	*lst = aid;
	return (lst);
}

static int	ft_check_inpute_file(char *file)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		ft_isfile(file, 0, R_OK);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	return (status);
}

void	ft_process_command(char **files, char *cmd, char **env, int trunc)
{
	char	**lst;
	char	*aid;
	int		tags;
	int		fd;
	int		i;

	tags = O_CREAT | O_WRONLY | O_TRUNC * trunc | O_APPEND * !trunc;
	fd = open(files[1], tags, 0644);
	if (ft_check_inpute_file(files[0]))
		return ;
	lst = ft_create_lst(cmd);
	ft_redirecting(files[0]);
	ft_isfile(files[1], 1, W_OK);
	free(files);
	aid = ft_execute(lst, env);
	ft_putstr_fd(aid, fd);
	free(aid);
	i = 0;
	while (lst[i])
		free(lst[i++]);
	free(lst);
	close(fd);
}
