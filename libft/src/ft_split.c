/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:08:43 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/02 16:57:09 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	w_count;
	size_t	in_word;
	size_t	i;

	i = 0;
	in_word = 0;
	w_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			w_count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (w_count);
}

static char	*ft_getword(char const *s, size_t start, size_t end)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = end - start;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_cleardata(char **arr, size_t k)
{
	while (k > 0)
	{
		k--;
		free(arr[k]);
	}
	free(arr);
	return (0);
}

static int	ft_putword(char **arr, char const *src, char c, size_t w_index)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (src[i] != '\0' && k < w_index)
	{
		if (src[i] != c)
		{
			j = i;
			while (src[j] && src[j] != c)
				j++;
			arr[k] = ft_getword(src, i, j);
			if (arr[k] == NULL)
				return (ft_cleardata(arr, k));
			i = j;
			k++;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char	const *s, char c)
{
	size_t	w_index;
	char	**arr;

	if (s == NULL)
		return (NULL);
	w_index = ft_wordcount(s, c);
	arr = (char **)malloc((w_index + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (!ft_putword(arr, s, c, w_index))
		return (NULL);
	arr[w_index] = NULL;
	return (arr);
}
/*int	main(void)
{
	char arr[] = "Hello+World+Nice+To+Meet+You";
	char **str;
	char c;
	int	i;

	c = '+';
	printf("Original String: %s\n", arr);
	str = ft_split(arr,c);
	
	i = 0;
	while (str[i] != NULL)
	{
		printf("str[%d] : %s\n", i, str[i]);
		i++;
	}
	return (0);
}*/
