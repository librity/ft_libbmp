/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:57:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/17 23:51:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static bool	out_of_bounds(t_mlx_image *image, int x, int y)
{
	if (x < 0)
		return (true);
	if (x > image->width)
		return (true);
	if (y < 0)
		return (true);
	if (y > image->height)
		return (true);
	return (false);
}

static int	get_index(t_mlx_image *image, int x, int y)
{
	return (y * image->line_length + x * image->bits_per_pixel / 8);
}

void	bm_draw_to_mlx_image(t_mlx_image *image, int x, int y, int color)
{
	int	*pixel_color;

	if (out_of_bounds(image, x, y))
		return ;
	pixel_color = (int *)&image->data[get_index(image, x, y)];
	*pixel_color = color;
}

void	bm_draw_rgb_to_mlx_image(t_mlx_image *image, int x, int y,
				t_rgb color)
{
	int	int_color;

	int_color = bm_rgb_to_int(color);
	bm_draw_to_mlx_image(image, x, y, int_color);
}

int	bm_get_mlx_image_pixel(t_mlx_image *image, int x, int y)
{
	int	*pixel_color;

	if (out_of_bounds(image, x, y))
		return (RED);
	pixel_color = (int *)&image->data[get_index(image, x, y)];
	return (*pixel_color);
}
