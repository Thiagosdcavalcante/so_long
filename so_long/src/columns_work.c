/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:18:58 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/21 12:00:41 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

t_data	*ft_newcolumns(char start, int line, int column)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	node->position = column;
	node->line = ft_lstnew(start, line);
	node->next = NULL;
	return (node);
}

void	ft_columnsadd_back(t_data **lst, t_data *new)
{
	t_data	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	if (!*lst)
		*lst = &(*new);
	else
	{
		while (temp -> next)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_columnsclear(t_data **lst)
{
	t_data	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (tmp)
	{
		lst = &(*lst)->next;
		ft_lstclear(&tmp->line);
		free(tmp);
		tmp = *lst;
	}
}
