/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:43:00 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/04 12:24:50 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_do_here_doc(int ac, char **av, int *trunc, char **files)
{
	int	fd;
	int	i;
	int	t;

	i = 1;
	t = 0;
	if (!ft_strncmp("here_doc", av[i], 9))
	{
		if (ac < 6)
		{
			ft_putendl_fd("Error: number of args", 2);
			exit(EXIT_FAILURE);
		}
		*trunc = 0;
		i += 1;
		fd = open(files[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		ft_putstr_fd(ft_here_doc(av[i]), fd);
		close(fd);
		av[i] = files[1];
	}
	else
		t = 1;
	close(open(av[ac - 1], O_CREAT | O_TRUNC * t, 0644));
	return (i);
}

static char	**ft_create_lst2(char *file1, char *file2)
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
	int		i;
	int		trunc;
	char	*files[2];
	char	**lst;

	files[0] = ".aid.txt";
	files[1] = ".aid2.txt";
	if (ac < 5)
	{
		ft_putendl_fd("Error: number of args", 2);
		exit(EXIT_FAILURE);
	}
	trunc = 1;
	i = ft_do_here_doc(ac, av, &trunc, files);
	ft_process_command(ft_create_lst2(av[i], files[0]), av[i + 1], env, 1);
	i += 2;
	while (i < ac - 2)
	{
		lst = ft_create_lst2(files[(i + trunc) % 2], files[(i - !trunc) % 2]);
		ft_process_command(lst, av[i], env, 1);
		i++;
	}
	lst = ft_create_lst2(files[(i + 1 - !trunc) % 2], av[i + 1]);
	ft_process_command(lst, av[i], env, trunc);
	ft_exit();
}
