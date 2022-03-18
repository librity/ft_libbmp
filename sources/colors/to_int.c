/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/17 23:05:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

int	bm_trgb_chars_to_int(
	unsigned char transparency,
	unsigned char red,
	unsigned char green,
	unsigned char blue
)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int	bm_rgb_chars_to_int(unsigned char red, unsigned char green,
		unsigned char blue)
{
	return (bm_trgb_chars_to_int(0, red, green, blue));
}

int	bm_trgb_to_int(t_trgb color)
{
	return (
		bm_trgb_chars_to_int(
			color.transparency,
			color.red,
			color.green,
			color.blue
		)
	);
}

int	bm_rgb_to_int(t_rgb color)
{
	return (
		bm_trgb_chars_to_int(
			0,
			color.red,
			color.green,
			color.blue
		)
	);
}
