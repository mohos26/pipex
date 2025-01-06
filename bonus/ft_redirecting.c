/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirecting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:51:36 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/02 13:16:45 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_redirecting(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("Error redirecting stdin");
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
