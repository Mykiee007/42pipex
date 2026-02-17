/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:53:00 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/02 11:52:08 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	list = *lst;
	while (list != NULL)
	{
		temp = list->next;
		ft_lstdelone(list, del);
		list = temp;
	}
	*lst = NULL;
}
