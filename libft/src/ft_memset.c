/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:07:06 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/11/27 12:50:53 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (src);
}

/*int main(void)
{
	char arr1[] = "Testing testing Texting";
	char arr2[] = "Testing testing Texting";
	//char arr[10];
	int i;
	char n;

	i = 0;
	n = '.';
	memset(arr1+4, n, 10);
	while (i < 10)
	{
		printf("%d ", arr1[i]);
		i++;
	}
	printf("%s", arr1);
	printf("\n");
	ft_memset(arr2+4, n, 10);
	i = 0;
	while (i < 10)
	{
		printf("%d ", arr2[i]);
		i++;
	}
	printf("%s", arr2);
	//printf("\nstring after memset(): %s\n", str);
	return (0);
}*/
