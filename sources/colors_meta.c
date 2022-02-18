/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_meta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 20:55:10 by lpaulo-m         ###   ########.fr       */
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

t_trgb	bm_int_to_trgb(int color)
{
	t_trgb	trgb;

	trgb.transparency = (unsigned char)(color >> 24);
	trgb.red = (unsigned char)(color >> 16);
	trgb.green = (unsigned char)(color >> 8);
	trgb.blue = (unsigned char)color;
	return (trgb);
}

t_bitmap_pixel	bm_int_to_rgb(int color)
{
	t_bitmap_pixel	rgb;

	rgb.red = (unsigned char)(color >> 16);
	rgb.green = (unsigned char)(color >> 8);
	rgb.blue = (unsigned char)color;
	return (rgb);
}
