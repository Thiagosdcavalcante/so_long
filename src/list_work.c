/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:32:05 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/23 18:10:52 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

t_list	*ft_lstnew(char content, int line, int column)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->column =  column;
	node->line =  line;
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (temp -> next)
			temp = temp->next;
		temp -> next = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = NULL;
	while (tmp)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	free(*lst);
}

