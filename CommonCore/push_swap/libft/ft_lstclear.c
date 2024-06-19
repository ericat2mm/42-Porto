/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:59:29 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/26 16:24:03 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*result;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		result = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = result;
	}
	*lst = NULL;
}
