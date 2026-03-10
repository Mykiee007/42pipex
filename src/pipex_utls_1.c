/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utls_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/09 14:00:10 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_join3(char *str1, char*str2, char *str3)
{
	char	*tmp;
	char	*result;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	if (!str3)
		str3 = "";
	tmp = ft_strjoin(str1, str2);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, str3);
	free (tmp);
	return (result);
}

void	close_all(t_pipex *px)
{
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->infile);
	close(px->outfile);
}
