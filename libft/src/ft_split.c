/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:08:43 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/13 14:50:27 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static int	ft_wordcount(char const *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			word_count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (word_count);
}

static void ft_get_word(char **result, char const *s, char c, int word_count)
{
	int i;
	int j;
	int w;
	int k;

	i = 0;
	j = 0;
	w = 0;
	while (s[i] && w < word_count)
	{
		while(s[i] && s[i] == c)
			i++;
		if (!s[i])
			break;
		j = i;
		while(s[j] && s[j] != c)
			j++;
		result[w] = (char *) malloc((j - i + 1) * sizeof(char));
		if (!result[w])
		{
			ft_free_split(result);
			return ;
		}
		k = 0;
		while(i < j)
		{
			result[w][k] = s[i];
			i++;
			k++;
		}
		result[w][k] = '\0';
		w++;
		i = j;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		w;
	
	w = ft_wordcount(s, c);
	result = (char **)malloc( (w + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_get_word(result, s, c, w);
	result[w] = NULL;
	return (result);
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
