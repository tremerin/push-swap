/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:28:58 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/05/06 10:29:10 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*lstfinal;

	if (!lst || !f)
		return (NULL);
	lstfinal = NULL;
	while (lst)
	{
		lstnew = ft_lstnew(f(lst->content));
		if (!lstnew)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&lstfinal, lstnew);
		lst = lst->next;
	}
	return (lstfinal);
}
