/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cllct_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:53:40 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/16 21:57:26 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

t_cllct	*ft_cllctnew(char content, int line, int column)
{
	t_cllct	*node;

	node = malloc(sizeof(t_cllct));
	if (node == NULL)
		return (NULL);
	node->active = 1;
	node->column = column;
	node->line = line;
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_cllctadd_back(t_cllct **lst, t_cllct *new)
{
	t_cllct	*temp;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
		temp = temp->next;
	temp -> next = new;
}

void	ft_cllctclear(t_cllct **lst)
{
	t_cllct	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
