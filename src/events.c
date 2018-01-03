/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:49:48 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/03 20:58:43 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	mousehook(int keycode, t_env *env)
{
}

int			keyhook(int keycode, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (keycode == 53)
		exit (0);
	return (0);
}
