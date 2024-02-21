/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_definition.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:18:12 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/21 12:04:44 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE_DEFINITION_H
# define SIZE_DEFINITION_H

# define START 150
# define WIDTH 1770
# define HEIGHT 800

typedef struct	s_sizes
{
	int	x;
	int	y;
	int	tile;
}	t_sizes;

void	tile_def(t_sizes *sizes);

#endif
