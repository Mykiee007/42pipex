/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:50:01 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/02/13 09:53:20 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"


int	main(int argc, char **argv)
{
	if (argc != 2) // should be 4
		return (0);
	printf("hello");
	fork();
	return (0);
}

