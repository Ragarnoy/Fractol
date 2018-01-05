/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:49:48 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/05 18:52:07 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void static	move(int keycode, t_env *env)
{
	double scale;

	scale = 0.1;
	if (scale < env->f[env->cur].zm_x * 500000)
		scale /= 10;
	if (keycode == 123)
		lat_move(&env->f[env->cur], -scale, 0);
	else if (keycode == 124)
		lat_move(&env->f[env->cur], scale, 0);
	else if (keycode == 125)
		lat_move(&env->f[env->cur], 0, -scale);
	else if (keycode == 126)
		lat_move(&env->f[env->cur], 0, scale);
	printf("%f:%f|%f:%f\n", env->f[env->cur].x[0],env->f[env->cur].y[0], env->f[env->cur].x[1],env->f[env->cur].y[1]);
	redraw(env);
}

void static	zoom(int keycode, t_env *env)
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
}

int			mousehook(int x, int y, void *param)
{
	t_env *env;

	env = (t_env*)param;
	printf("%d:%d\n", x,y);
	return (0);
}

int			keyhook(int keycode, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (keycode == 53)
		exit (0);
	if (keycode == 116 && !(env->cur + 1 > FRCTNB))
	{
		env->cur++;
		redraw(env);
	}
	else if (keycode == 121 && env->cur > 0)
	{
		env->cur--;
		redraw(env);
	}
	if (keycode == 69 || keycode == 78)
		zoom(keycode, env);
	if (keycode >= 123 && keycode <= 126)
		move(keycode, env);
	return (0);
}
