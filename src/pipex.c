/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:43:00 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/05 13:05:00 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	**ft_create_lst(char *file1, char *file2)
{
	char	**res;

	res = malloc(sizeof(char *) * 2);
	if (!res)
	{
		perror("Allocation");
		ft_exit();
	}
	res[0] = file1;
	res[1] = file2;
	return (res);
}

int	main(int ac, char **av, char **env)
{
	char	*aid_file;

	aid_file = ".aid.txt";
	if (ac != 5)
	{
		ft_putendl_fd("Error: number of args", 2);
		exit(EXIT_FAILURE);
	}
	ft_process_command(ft_create_lst(av[1], aid_file), av[2], env, 1);
	ft_process_command(ft_create_lst(aid_file, av[4]), av[3], env, 1);
	ft_exit();
}
