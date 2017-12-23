/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:49:48 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/23 19:23:08 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	keyhook(int keycode, t_env *env)
{
}

static void	mousehook(int keycode, t_env *env)
{
}

int			events(int keycode,void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (keycode == 53)
		;
	return (0);
}
