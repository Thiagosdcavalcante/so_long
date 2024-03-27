/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:45:42 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/23 16:50:38 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	check_size(long check_n)
{
	size_t	i;

	i = 0;
	if (check_n < 0)
		check_n *= (-1);
	while (check_n > 0)
	{
		check_n /= 10;
		i++;
	}
	return (i);
}

static void	def_calloc(char **dest, long src_int)
{
	size_t	size;

	if (src_int == 0)
		*dest = ft_calloc(2, sizeof(char));
	else if (src_int < 0)
	{
		size = check_size(src_int);
		*dest = ft_calloc((size + 2), sizeof(char));
	}
	else
	{
		size = check_size(src_int);
		*dest = ft_calloc((size + 1), sizeof(char));
	}
}

static void	neg_str(char **dst, long int src)
{
	size_t	ind;

	ind = (check_size(src) + 1);
	(*dst)[ind] = '\0';
	(*dst)[0] = '-';
	ind--;
	src *= -1;
	while (ind >= 1 || src > 0)
	{
		(*dst)[ind] = (src % 10) + '0';
		ind--;
		src /= 10;
	}
}

static void	posit_str(char **pdst, long int src)
{
	size_t	j;

	j = (check_size(src));
	(*pdst)[j] = '\0';
	while (j > 0)
	{
		j--;
		(*pdst)[j] = (src % 10) + '0';
		src /= 10;
	}
}

char	*ft_itoa(int n)
{
	long int	src;
	char		*numb;

	src = (long int)n;
	def_calloc(&numb, src);
	if (numb == NULL)
		return (NULL);
	if (n == 0)
	{
		numb[0] = '0';
		numb[1] = '\0';
	}
	if (n < 0)
		neg_str(&numb, src);
	if (n > 0)
		posit_str(&numb, src);
	return (numb);
}
