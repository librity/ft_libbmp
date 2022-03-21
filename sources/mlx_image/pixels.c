/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:57:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 14:18:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static bool	out_of_bounds(t_mlx_image *image, int x, int y)
{
	if (x < 0)
		return (true);
	if (x >= image->width)
		return (true);
	if (y < 0)
		return (true);
	if (y >= image->height)
		return (true);
	return (false);
}

static int	get_index(t_mlx_image *image, int x, int y)
{
	return (y * image->line_length + x * image->bits_per_pixel / 8);
}

void	mlx_image_draw_int(t_mlx_image *image, int color, int x, int y)
{
	int	*pixel_color;

	if (out_of_bounds(image, x, y))
		return ;
	pixel_color = (int *)&image->data[get_index(image, x, y)];
	*pixel_color = color;
}

void	mlx_image_draw_rgb(t_mlx_image *image, t_rgb color, int x, int y)
{
	int	int_color;

	int_color = rgb_to_int(color);
	mlx_image_draw_int(image, int_color, x, y);
}

int	mlx_image_get_pixel_int(t_mlx_image *image, int x, int y)
{
	int	*pixel_color;

	if (out_of_bounds(image, x, y))
		return (RED);
	pixel_color = (int *)&image->data[get_index(image, x, y)];
	return (*pixel_color);
}
