/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/22 10:36:35 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *c)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while (c[i] == ' ' || (c[i] > 8 && c[i] < 14))
		i++;
	if (c[i] == '+' || c[i] == '-')
	{
		if (c[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (c[i] >= '0' && c[i] <= '9')
	{
		result = (result * 10) + (c[i] - '0');
		i++;
	}
	return (result * sign);
}
