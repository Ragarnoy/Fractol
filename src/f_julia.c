/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:37:00 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/09 21:31:02 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	compute(t_hsl pal[], t_frc jl, int y, int y_max)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = y - 1)))
	{
		while (++pt.y < y_max && ((i = -1)))
		{
			jl.z_r = pt.x / jl.zm_x + jl.x[0];
			jl.z_i = pt.y / jl.zm_y + jl.y[0];
			while ((jl.z_r * jl.z_r) + (jl.z_i * jl.z_i)
					< 4 && ++i < jl.i_max)
			{
				jl.tmp = jl.z_r;
				jl.z_r = (jl.z_r * jl.z_r) - (jl.z_i * jl.z_i) + jl.c_r;
				jl.z_i = (2 * jl.z_i * jl.tmp) + jl.c_i;
			}
			if (i == jl.i_max)
				put_hslpixel(pal[COLNB - 1], pt, 1);
			else
				put_hslpixel(gethsl((i % 100) + jl.cl.h, jl.cl.s, jl.cl.l), pt, 0);
		}
	}
}

void		julia(t_env *env, t_pnt *thrd)
{
	if (!env->f[1].init)
	{
		env->f[1].x[0] = -1;
		env->f[1].x[1] = 1;
		env->f[1].y[0] = -1.2;
		env->f[1].y[1] = 1.2;
		env->f[1].zm_x = W_WDTH / (env->f[1].x[1] - env->f[1].x[0]);
		env->f[1].zm_y = W_HGHT / (env->f[1].y[1] - env->f[1].y[0]);
		env->f[1].i_max = 22;
		env->f[1].init = 1;
		env->f[1].cl.h = 1.0;
		env->f[1].cl.s = 1.0;
		env->f[1].cl.l = 0.5;
		return;
	}
	compute (env->pal[0], env->f[1], thrd->x, thrd->y);
}
