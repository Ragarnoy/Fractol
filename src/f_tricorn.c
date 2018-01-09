/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:40:23 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/09 21:36:10 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	compute(t_hsl pal[], t_frc tc, int y, int y_max)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = y - 1)))
	{
		while (++pt.y < y_max && ((i = -1)))
		{
			tc.c_r = pt.x / tc.zm_x + tc.x[0];
			tc.c_i = pt.y / tc.zm_y + tc.y[0];
			tc.z_r = 0;
			tc.z_i = 0;
			while ((tc.z_r * tc.z_r) + (tc.z_i * tc.z_i)
					< 4 && ++i < tc.i_max)
			{
				tc.tmp = tc.z_r;
				tc.z_r = (tc.z_r * tc.z_r) - (tc.z_i * tc.z_i) + tc.c_r;
				tc.z_i = (-2 * tc.z_i * tc.tmp) + tc.c_i;
			}
			if (i == tc.i_max)
				put_hslpixel(pal[COLNB - 1], pt, 2);
			else
				put_hslpixel(gethsl((i % 361) + tc.cl.h, tc.cl.s, tc.cl.l), pt, 0);
		}
	}
}

void		tricorn(t_env *env, t_pnt *thrd)
{
	if (!env->f[2].init)
	{
		env->f[2].x[0] = -1.68;
		env->f[2].x[1] = 1.30;
		env->f[2].y[0] = -1.2;
		env->f[2].y[1] = 1.2;
		env->f[2].zm_x = W_WDTH / (env->f[2].x[1] - env->f[2].x[0]);
		env->f[2].zm_y = W_HGHT / (env->f[2].y[1] - env->f[2].y[0]);
		env->f[2].i_max = 22;
		env->f[2].cl.h = 1;
		env->f[2].cl.s = 1.0;
		env->f[2].cl.l = 0.5;
		env->f[2].init = 1;
		return;
	}
	compute (env->pal[0], env->f[2], thrd->x, thrd->y);
}
