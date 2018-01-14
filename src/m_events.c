/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:04:17 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/14 01:44:03 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			pointerhook(int x, int y, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if ((env->cur == 1 || env->cur >= 8) && env->flag.mouse)
	{
		env->f[env->cur].c_r = x * ((double)3 / W_WDTH) - 1.6;
		env->f[env->cur].c_i = y * ((double)2 / W_HGHT) - 1;
		redraw(env);
	}
	if (env->flag.shift && env->flag.click && (env->cur != 1 && env->cur < 8))
		click_n_drag(x, y, &env->f[env->cur]);
	if ((env->cur == 1 || env->cur >= 8) && !env->flag.mouse &&
			env->flag.click && env->flag.shift)
		click_n_drag(x, y, &env->f[env->cur]);
	return (0);
}

int			mousehook(int btn, int x, int y, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (y > 1)
	{
		if ((btn == 1 || btn == 4) && !env->flag.shift &&
				env->f[env->cur].zml < 155)
		{
			zoom_in(&env->f[env->cur], x, y);
			++env->f[env->cur].zml;
			redraw(get_env());
		}
		if ((btn == 2 || btn == 5) && !env->flag.shift &&
				env->f[env->cur].i_max > 2)
		{
			zoom_out(&env->f[env->cur], x, y);
			--env->f[env->cur].zml;
			redraw(get_env());
		}
		if (env->flag.shift && btn == 1)
			env->flag.click = 1;
		if (!env->flag.shift)
			env->flag.click = 0;
	}
	return (0);
}

int			releasehook(int button, int x, int y, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (button == 1)
	{
		env->flag.click = 0;
		env->f[env->cur].tmp_x = 0;
	}
	x = y;
	return (0);
}
