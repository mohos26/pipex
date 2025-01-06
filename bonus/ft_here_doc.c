/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:54:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/03 18:35:49 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_here_doc(char *delimiter)
{
	char	*input;
	char	*res;
	int		len;

	len = ft_strlen(delimiter);
	delimiter[len] = '\n';
	len++;
	res = NULL;
	while (1)
	{
		ft_putstr_fd("heredoc> ", 0);
		input = get_next_line(0);
		if (!input || !ft_strncmp(input, delimiter, len))
			break ;
		res = ft_strjoin(res, input);
		if (!(len - 1))
			break ;
	}
	return (res);
}
