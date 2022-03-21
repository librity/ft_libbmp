/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:17:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 14:02:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

int	abs(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

void	putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}
