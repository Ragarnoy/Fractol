/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:49:48 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/08 21:35:18 by tlernoul         ###   ########.fr       */
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

void static	colorcontrol(int keycode, t_env *env)
{
	 if (keycode == 38)
		env->f[env->cur].cl.h++;
	else if (keycode == 46)
		env->f[env->cur].cl.h--;
	 if (keycode == 40)
		env->f[env->cur].cl.s += 0.05;
	else if (keycode == 43)
		env->f[env->cur].cl.s -= 0.05;
	 if (keycode == 37)
		env->f[env->cur].cl.l += 0.05;
	else if (keycode == 47)
		env->f[env->cur].cl.l -= 0.05;
		redraw(env);
}

int			keyhook(int keycode, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (keycode == 53)
		exit (0);
	else if (keycode == 116 && env->cur < FRCTNB && ++env->cur)
		redraw(env);
	else if (keycode == 121 && env->cur > 0 && env->cur--)
		redraw(env);
	else if (keycode == 119)
		env->flag.mouse = !env->flag.mouse;
	else if (keycode == 257)
		env->flag.shift = 1;
	else if (keycode >= 123 && keycode <= 126)
		move(keycode, env);
	else if (keycode == 71 && !(env->f[env->cur].init = 0))
		redraw(env);
	else if (keycode > 37 && keycode < 48)
		colorcontrol(keycode, env);
	else if (keycode == 4)
	{
		env->flag.help = !env->flag.help;
		redraw(env);
	}
	else if (keycode == 279)
		printf("DEBUG\n-X = %f || %f\n-Y = %f || %f\n",env->f[env->cur].x[0], env->f[env->cur].x[1], env->f[env->cur].y[0], env->f[env->cur].y[1]);
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
