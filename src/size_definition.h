/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_definition.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:18:12 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 19:49:01 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE_DEFINITION_H
# define SIZE_DEFINITION_H

# define START 150
# define WIDTH 1770
# define HEIGHT 800

typedef struct	s_sizes
{
	int	qnt_f;
	int	qnt_p;
	int	qnt_e;
	int	x;
	int	y;
	int	tile;
}	t_sizes;

int	tile_def(int x, int y);

#endif
