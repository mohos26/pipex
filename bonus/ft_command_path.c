/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:44:56 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/04 10:59:26 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_command_path(char *command)
{
	char	*lst[3];
	char	*res;

	lst[0] = "/usr/bin/whereis";
	lst[1] = command;
	lst[2] = NULL;
	res = ft_execute(lst, NULL);
	if (!ft_strlen(res))
	{
		ft_putstr_fd(command, 2);
		ft_putendl_fd(": command not found", 2);
		return (NULL);
	}
	res[ft_strlen(res)-1] = '\0';
	return (res);
}
