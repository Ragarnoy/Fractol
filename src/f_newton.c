/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_newton.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:59:11 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/14 01:42:07 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	calculus(double *z_r, double *z_i)
{
	double tmp;
	double cl;

	cl = 3 * ((((*z_r * *z_r) - (*z_i * *z_i)) * ((*z_r * *z_r) -
					(*z_i * *z_i))) + ((2 * *z_r * *z_i) * (2 * *z_r * *z_i)));
	tmp = *z_r;
	*z_r = ((*z_r / 3) * 2) + ((*z_r * *z_r) - (*z_i * *z_i)) / cl;
	*z_i = ((*z_i / 3) * 2) - (2 * tmp * *z_i) / cl;
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
			z_r = (double)pt.x / mb.zm_x + mb.x[0];
			z_i = (double)pt.y / mb.zm_y + mb.y[0];
			while (++i < mb.i_max)
				calculus(&z_r, &z_i);
			if (z_i < -sqrt(3) / 4)
				putpixel(mb.cl[0], pt);
			else if (z_i > sqrt(3) / 4)
				putpixel(gethsl(120, 1, 0), pt);
			else
				putpixel(mb.cl[1], pt);
		}
	}
}

void		newton(t_env *env, t_pnt *thrd)
{
	if (!env->f[5].init)
	{
		env->f[5].x[0] = -1;
		env->f[5].x[1] = 1;
		env->f[5].y[0] = -1;
		env->f[5].y[1] = 1;
		env->f[5].zm_x = W_WDTH / (env->f[5].x[1] - env->f[5].x[0]);
		env->f[5].zm_y = W_HGHT / (env->f[5].y[1] - env->f[5].y[0]);
		env->f[5].i_max = 25;
		env->f[5].cl[0].h = 30;
		env->f[5].cl[0].s = 1;
		env->f[5].cl[0].l = 1;
		env->f[5].zml = 0;
		env->f[5].init = 1;
		return ;
	}
	compute(env->f[5], thrd->x, thrd->y);
}
