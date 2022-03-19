/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:32:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/19 00:34:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

void	bm_destroy_mlx_image(t_mlx_image *image)
{
	mlx_destroy_image(image->mlx, image->img);
}
