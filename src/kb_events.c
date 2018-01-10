/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:49:48 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/10 23:50:20 by tlernoul         ###   ########.fr       */
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

void static	keypad(int keycode, t_env *env)
{
	if (keycode == 86)
		env->f[env->cur].cl[env->flag.swi].h++;
	else if (keycode == 83)
		env->f[env->cur].cl[env->flag.swi].h--;
	else if (keycode == 87 && env->f[env->cur].cl[env->flag.swi].s < 1.0)
		env->f[env->cur].cl[env->flag.swi].s += 0.05;
	else if (keycode == 84 && env->f[env->cur].cl[env->flag.swi].s > 0)
		env->f[env->cur].cl[env->flag.swi].s -= 0.05;
	else if (keycode == 88 && env->f[env->cur].cl[env->flag.swi].l < 1.0)
		env->f[env->cur].cl[env->flag.swi].l += 0.05;
	else if (keycode == 85 && env->f[env->cur].cl[env->flag.swi].l > 0)
		env->f[env->cur].cl[env->flag.swi].l -= 0.05;
	else if (keycode == 81)
		env->flag.rot = !env->flag.rot;
	else if (keycode == 71)
		env->f[env->cur].init = 0;
	else if (keycode == 78 && env->f[env->cur].i_max > 2)
		env->f[env->cur].i_max -= 2;
	else if (keycode == 69)
		env->f[env->cur].i_max += 2;
	else if (keycode == 65)
		env->flag.swi = !env->flag.swi;
	redraw(env);
}

void static	misc_key(int keycode, t_env *env)
{
	if (keycode == 257)
		env->flag.shift = 1;
	else if (keycode == 4)
	{
		printf("%.20f:%.20f || %.20f:%.20f\nzm %.20f || %.20f\n", env->f[env->cur].x[0],env->f[env->cur].x[1],env->f[env->cur].y[0],env->f[env->cur].y[1], env->f[env->cur].zm_x,env->f[env->cur].zm_y);
		printf("%.20f:%.20f\n", env->f[env->cur].x[0]/env->f[env->cur].x[1],env->f[env->cur].y[0]/env->f[env->cur].y[1]);
		env->flag.help = !env->flag.help;
	}
	else if (keycode == 24 && env->curp < PALNB - 1)
		env->curp++;
	else if (keycode == 27 && env->curp > 0)
		env->curp--;
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
	else if (keycode >= 123 && keycode <= 126)
		move(keycode, env);
	else if (keycode >= 65 && keycode <= 88)
		keypad(keycode, env);
	else if (keycode == 257 || keycode == 4 || (keycode >= 24 && keycode <= 27))
		misc_key(keycode, env);
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
