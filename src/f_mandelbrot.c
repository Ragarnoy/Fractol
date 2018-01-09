/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:39:36 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/10 00:56:03 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	compute(t_hsl pal[], t_frc mb, int y, int y_max)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_HGHT && ((pt.y = y - 1)))
	{
		while (++pt.y < y_max && ((i = -1)))
		{
			mb.c_r = (double)pt.x / mb.zm_x + mb.x[0];
			mb.c_i = (double)pt.y / mb.zm_y + mb.y[0];
			mb.z_r = 0;
			mb.z_i = 0;
			while ((mb.z_r * mb.z_r) + (mb.z_i * mb.z_i)
					< 4 && ++i < mb.i_max)
			{
				mb.tmp = mb.z_r;
				mb.z_r = (mb.z_r * mb.z_r) - (mb.z_i * mb.z_i) + mb.c_r;
				mb.z_i = (2 * mb.z_i * mb.tmp) + mb.c_i;
			}
			if (i == mb.i_max)
				put_hslpixel(pal[COLNB - 1], pt, 2);
			else
				put_hslpixel(hslrange(gethsl(288, 0.5, 0), gethsl(288, 0.5, 0.7) ,(float)i / (float)mb.i_max), pt, 0);
		}
	}
}

void		mandelbrot(t_env *env, t_pnt *thrd)
{
	if (!env->f[0].init)
	{
		env->f[0].x[0] = -2.1;
		env->f[0].x[1] = 0.6;
		env->f[0].y[0] = -1.2;
		env->f[0].y[1] = 1.2;
		env->f[0].zm_x = W_WDTH / (env->f[0].x[1] - env->f[0].x[0]);
		env->f[0].zm_y = W_HGHT / (env->f[0].y[1] - env->f[0].y[0]);
		env->f[0].i_max = 25;
		env->f[0].cl.h = 10;
		env->f[0].cl.s = 1.0;
		env->f[0].cl.l = 0.5;
		env->f[0].init = 1;
		return;
	}
	compute (env->pal[1], env->f[0], thrd->x, thrd->y);
}
