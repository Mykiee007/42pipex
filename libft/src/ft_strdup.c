/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:29:45 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/27 10:00:05 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		length;
	char	*p;

	i = 0;
	while (s[i] != '\0')
		i++;
	length = i + 1;
	p = (char *)malloc(length * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*int main(void)
{
	char str[] = "Hello World!";
	char *target;

	target = ft_strdup(str);
	if (target == NULL)
		return (1);
	
	printf("Original file: %s\n", str);
	printf("Duplicate file: %s\n", target);
	return (0);
}*/
