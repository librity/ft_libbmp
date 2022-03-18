/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:22:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 20:23:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static bool	out_of_bounds(t_bitmap_image *image, int row, int column)
{
	if (row < 0)
		return (true);
	if (row >= image->header.height)
		return (true);
	if (column < 0)
		return (true);
	if (column >= image->header.width)
		return (true);
	return (false);
}

void	bm_set_image_pixel(t_bitmap_image *image,
						t_bitmap_pixel color,
						int row,
						int column)
{
	t_bitmap_pixel	*target_pixel;

	if (out_of_bounds(image, row, column))
		return ;
	target_pixel = &image->pixels[row][column];
	bm_set_pixel(target_pixel, color.red, color.green, color.blue);
}

void	bm_set_pixel(t_bitmap_pixel *pxl,
					unsigned char red,
					unsigned char green,
					unsigned char blue)
{
	pxl->red = red;
	pxl->green = green;
	pxl->blue = blue;
}
