/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:01:33 by vflores           #+#    #+#             */
/*   Updated: 2024/11/20 12:01:38 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.

*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*start;
	void	*content;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (!content && new_lst)
			return (ft_lstclear(&new_lst, del), NULL);
		start = ft_lstnew(content);
		if (!start)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, start);
		lst = lst->next;
	}
	return (new_lst);
}
