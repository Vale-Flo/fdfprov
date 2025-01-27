/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:02:59 by vflores           #+#    #+#             */
/*   Updated: 2024/11/20 12:03:01 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst)
		return ;
	start = *lst;
	while (start != NULL)
	{
		tmp = start->next;
		del(start->content);
		free (start);
		start = tmp;
	}
	*lst = NULL;
}
