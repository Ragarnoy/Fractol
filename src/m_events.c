/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:04:17 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 07:20:16 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			pointerhook(int x, int y, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (env->cur == 1 && env->flag.mouse)
	{
		env->f[1].c_r = x * ((double)2.4 / W_WDTH) - 1.7;
		env->f[1].c_i = y * ((double)2 / W_HGHT) - 1;
		redraw(env);
	}
	if (env->flag.shift && env->flag.click)
		click_n_drag(x, y, &env->f[env->cur]);
	return (0);
}

int			mousehook(int button, int x, int y, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (button > 0 && button < 6 && button != 3 && !env->flag.shift)
		zoom_pt(&env->f[env->cur], x, y, button);
	if (env->flag.shift && button == 1)
		env->flag.click = 1;
	return (0);
}

int			releasehook(int button, int x, int y, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (env->flag.shift && button == 1)
	{
		env->flag.click = 0;
		env->f[env->cur].tmp_x = 0;
	}
	x = y;
	return (0);
}
