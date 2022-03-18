/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:43:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/17 23:51:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static void	transfer_pixels(t_mlx_image *image, t_bitmap_image *bm_image)
{
	int				column;
	int				row;
	int				color;
	t_bitmap_pixel	bm_color;

	row = image->height;
	while (row--)
	{
		column = image->width;
		while (column--)
		{
			color = bm_get_mlx_image_pixel(image, column, row);
			bm_color = bm_int_to_rgb(color);
			bm_set_image_pixel(bm_image, bm_color, image->height - row - 1,
				column);
		}
	}
}

void	bm_save_mlx_image(t_mlx_image *image, char *filename)
{
	t_bitmap_image	bm_image;

	bm_initialize_bitmap(&bm_image, image->width, image->height);
	transfer_pixels(image, &bm_image);
	bm_save_bitmap(&bm_image, filename);
	bm_free_bitmap(&bm_image);
}
