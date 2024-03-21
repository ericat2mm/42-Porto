/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:23 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/26 16:39:55 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*mapped_content;

	new_list = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		new_node = ft_lstnew(mapped_content);
		if (!mapped_content || !new_node)
		{
			if (del)
				del(mapped_content);
			if (new_list)
				ft_lstclear(&new_list, del);
			if (new_node)
				free(new_node);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
