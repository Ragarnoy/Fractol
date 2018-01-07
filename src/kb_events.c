/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:49:48 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 07:35:38 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void static	move(int keycode, t_env *env)
{
	double scale;

	scale = 0.05;
	if (keycode == 123)
		lat_move(&env->f[env->cur], -scale, 0);
	else if (keycode == 124)
		lat_move(&env->f[env->cur], scale, 0);
	else if (keycode == 125)
		lat_move(&env->f[env->cur], 0, scale);
	else if (keycode == 126)
		lat_move(&env->f[env->cur], 0, -scale);
	redraw(env);
}

/*void static	zoom(int keycode, t_env *env)
{
	if (keycode == 69)
	{
		env->f[env->cur].zm_x *= 1.02;
		env->f[env->cur].zm_y *= 1.02;
	}
	if (keycode == 78)
	{
		env->f[env->cur].zm_x /= 1.02;
		env->f[env->cur].zm_y /= 1.02;
	}
	printf("%f|%f\n", env->f[env->cur].zm_x,env->f[env->cur].zm_y);
	redraw(env);
}*/


int			keyhook(int keycode, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (keycode == 53)
		exit (0);
	if (keycode == 116 && env->cur < FRCTNB && ++env->cur)
		redraw(env);
	if (keycode == 121 && env->cur > 0 && env->cur--)
		redraw(env);
	if (keycode == 119)
		env->flag.mouse = !env->flag.mouse;
	if (keycode == 257)
		env->flag.shift = 1;
	/*if (keycode == 69 || keycode == 78)
		zoom(keycode, env);*/
	if (keycode >= 123 && keycode <= 126)
		move(keycode, env);
	if (keycode == 71 && !(env->f[env->cur].init = 0))
		redraw(env); //marche pas
	return (0);
}

int			shifthook(int keycode, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (keycode == 257)
		env->flag.shift = 0;
	return (0);
}
