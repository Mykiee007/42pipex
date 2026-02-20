/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/02/19 13:22:04 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	int i;
	int fd = access(argv[1], (W_OK | R_OK) & X_OK);

    if (argc != 5)
    {
		ft_printf("please give 4 arguments");
	   return (0);
	}
	if (fd == -1)
	{
		perror("error in Perror");
		ft_printf("%s\n",strerror(errno));
		ft_printf("Error Numbers: %d\n", errno);
	}
	else
		ft_printf("no error\n");
    i = argc;
    while (i >= 0)
    {
        ft_printf("The statement: %s\n", argv[i]);
        check(i);
        i--;
    }   
    return (0);
}