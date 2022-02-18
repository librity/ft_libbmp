/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 20:48:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

int	bm_get_t(int color)
{
	return (color & T_MASK);
}

int	bm_get_r(int color)
{
	return (color & R_MASK);
}

int	bm_get_g(int color)
{
	return (color & G_MASK);
}

int	bm_get_b(int color)
{
	return (color & B_MASK);
}

int	bm_zero_transparency(int color)
{
	int	transparency;

	transparency = color >> 24 << 24;
	color = color - transparency;
	return (color);
}
