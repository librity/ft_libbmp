/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 14:40:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static void	print_error(char *message)
{
	while (*message)
		write(1, message++, 1);
}

typedef struct s_example
{
	char	*file_name;

	int		width;
	int		height;

	double	red_float;
	double	green_float;
	double	blue_float;

	int		red_int;
	int		green_int;
	int		blue_int;

	t_rgb	color_rgb;
}			t_example;

static void	initialize_control(t_example *control, char **arguments)
{
	control->file_name = arguments[1];
	control->width = 1920;
	control->height = 1080;
	control->blue_float = 0.75;
	control->blue_int = (int)(255.999 * control->blue_float);
}

static void	set_pixels(void *bitmap, t_example *c)
{
	int		x;
	int		y;

	x = c->width;
	while (x--)
	{
		y = c->height;
		while (y--)
		{
			c->red_float = (double)x / (c->width - 1);
			c->green_float = (double)y / (c->height - 1);
			c->red_int = (int)(255.999 * c->red_float);
			c->green_int = (int)(255.999 * c->green_float);

			c->color_rgb = color_rgb(c->red_int, c->green_int, c->blue_int);
			bm_draw(bitmap, c->color_rgb, x, y);
		}
	}
}

static void	handle_arguments(int argument_count)
{
	if (argument_count != 2)
	{
		print_error("ERROR: expected one argument as filename.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_example	c;
	void		*bitmap;

	handle_arguments(argc);
	initialize_control(&c, argv);
	bitmap = bm_initialize(c.width, c.height);
	set_pixels(bitmap, &c);
	bm_save(bitmap, c.file_name);
	bm_free(bitmap);
	return (0);
}
