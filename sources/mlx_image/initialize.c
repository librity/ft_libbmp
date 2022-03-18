/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:32:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/17 23:49:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static void	die_if_null(void *ptr)
{
	if (ptr == NULL)
		die();
}

void	initialize_mlx_image(t_mlx_image *image, void *mlx,
			int width, int height)
{
	image->img = mlx_new_image(mlx, width, height);
	die_if_null(image->img);
	image->data = mlx_get_data_addr(image->img,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
	die_if_null(image->data);
	image->width = width;
	image->height = height;
	image->half_width = width / 2.0;
	image->half_height = height / 2.0;
}
