/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:39:36 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/12 21:34:17 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	calculus(double *c_r, double *c_i, double *z_r, double *z_i)
{
	double tmp;

	tmp = *z_r;
	*z_r = (*z_r * *z_r) - (*z_i * *z_i) + *c_r;
	*z_i = (2 * *z_i * tmp) + *c_i;
}

static void	compute(t_frc mb, int y, int y_max)
{
	t_pnt			pt;
	unsigned int	i;
	double			z_r;
	double			z_i;

	pt.x = -1;
	while (++pt.x < W_HGHT && ((pt.y = y - 1)))
	{
		while (++pt.y < y_max && ((i = -1)))
		{
			mb.c_r = (double)pt.x / mb.zm_x + mb.x[0];
			mb.c_i = (double)pt.y / mb.zm_y + mb.y[0];
			z_r = 0;
			z_i = 0;
			while ((z_r * z_r) + (z_i * z_i)
					< 4 && ++i < mb.i_max)
				calculus(&mb.c_r, &mb.c_i, &z_r, &z_i);
			if (i == mb.i_max)
				putpixel(mb.cl[0], pt);
			else
				picker(mb.cl[1], (float)i / (float)mb.i_max, pt);
		}
	}
}

void		mandelbrot(t_env *env, t_pnt *thrd)
{
	if (!env->f[0].init)
	{
		env->f[0].x[0] = -2.35;
		env->f[0].x[1] = 0.58;
		env->f[0].y[0] = -1.50;
		env->f[0].y[1] = 1.49;
		env->f[0].zm_x = W_WDTH / (env->f[0].x[1] - env->f[0].x[0]);
		env->f[0].zm_y = W_HGHT / (env->f[0].y[1] - env->f[0].y[0]);
		env->f[0].i_max = 25;
		env->f[0].cl[0].h = 30;
		env->f[0].cl[0].s = 1;
		env->f[0].cl[0].l = 1;
		env->curp = 0;
		env->f[0].zml = 0;
		env->f[0].init = 1;
		return ;
	}
	compute(env->f[0], thrd->x, thrd->y);
}
