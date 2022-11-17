/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:57:51 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/06 14:56:30 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

bool	lst_create_back(t_list **lst, void *data)
{
	t_list	*new;

	new = lst_new(data);
	if (NULL == data)
		return (false);
	return (lst_add_back(lst, new), true);
}
/*
bool	lst_transform(t_list **lst, t_iterator iterator)
{
	t_list	*output;
	t_list	*tmp;

	output = NULL;
	while (lst)
	{
		tmp = lstnew(lst->content);
		if (NULL == tmp)
			return (lstclear(&output, iterator.deletion), NULL);
		if (false == iterator.iterator(&tmp->content))
			return (lstclear(&output, iterator.deletion), NULL);
		lstadd_back(&output, tmp);
		lst = lst->next;
	}
	return (output);
}

t_list	*lst_map_not_null(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	void	*data;
	t_list	*tmp;
	t_list	*out;

	output = NULL;
	while (lst)
	{
		data = f(lst->content);
		tmp = lstnew(lst->content);
		if (NULL == tmp)
			return (lstclear(&output, del), NULL);
		if (false == iterator.iterator(&tmp->content))
			return (lstclear(&output, iterator.deletion), NULL);
		lstadd_back(&output, tmp);
		lst = lst->next;
	}
	return (output);
}
*/
