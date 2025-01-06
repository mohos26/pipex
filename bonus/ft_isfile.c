/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 08:48:06 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/05 13:07:00 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	**ft_create_lst(char *file_name)
{
	char	**lst;

	lst = malloc(4 * sizeof(char *));
	if (!lst)
	{
		perror("Allocation");
		exit(EXIT_FAILURE);
	}
	lst[0] = ft_command_path("file");
	lst[1] = "-b";
	lst[2] = file_name;
	lst[3] = NULL;
	return (lst);
}

static void	ft_aid(char *file_name, char **lst, char c)
{
	int	i;

	i = 0;
	while (lst[i])
		free(lst[i++]);
	free(lst);
	if (!c)
	{
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(21), 2);
		exit(EXIT_FAILURE);
	}
}

static void	ft_check_dir(char *file_name)
{
	char	**lst;
	char	*aid3;
	char	*aid;
	int		i;

	lst = ft_create_lst(file_name);
	aid = ft_execute(lst, NULL);
	free(*lst);
	free(lst);
	lst = ft_split(aid, ' ');
	free(aid);
	i = 0;
	while (lst[i])
		aid = lst[i++];
	aid3 = "directory";
	while (*aid3)
		if (!(*aid && *aid++ == *aid3++))
			break ;
	ft_aid(file_name, lst, *aid3);
}

void	ft_isfile(char *file_name, int check_dir, int check_permision)
{
	if (access(file_name, check_permision))
	{
		perror(file_name);
		exit(EXIT_FAILURE);
	}
	if (check_dir)
		ft_check_dir(file_name);
}
