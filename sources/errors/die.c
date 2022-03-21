/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:17:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 14:17:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static char	*g_error_messages[GENERIC_BITMAP_ERROR] = {
	"Error creating file.",
	"Header didn't initialize properly.",
	"Unable to allocate required memory.",
	"Error initializing mlx image.",
	"Generic bitmap error.",
};

static void	print_error(char *message)
{
	putstr("\033[0;31mERROR\n");
	putstr(message);
	putstr("\033[0m\n");
}

void	die(t_errors code)
{
	print_error(g_error_messages[code]);
	exit(EXIT_FAILURE);
}

void	die_if_null(void *ptr, t_errors code)
{
	if (ptr == NULL)
		die(code);
}
