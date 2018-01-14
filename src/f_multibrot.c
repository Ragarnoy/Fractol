/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_multibrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:42:35 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/14 02:02:54 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	calculus(double *c_r, double *c_i, double *z_r, double *z_i)
{
	double tmp;

	tmp = *z_r;
	*z_r = (*z_r * *z_r * *z_r) - 3 * *z_r * (*z_i * *z_i) + *c_r;
	*z_i = (3 * (tmp * tmp) * *z_i - (*z_i * *z_i * *z_i)) + *c_i;
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

void		multibrot(t_env *env, t_pnt *thrd)
{
	if (!env->f[4].init)
	{
		env->f[4].x[0] = -1.15;
		env->f[4].x[1] = 1.15;
		env->f[4].y[0] = -1.50;
		env->f[4].y[1] = 0.9;
		env->f[4].zm_x = W_WDTH / (env->f[4].x[1] - env->f[4].x[0]);
		env->f[4].zm_y = W_HGHT / (env->f[4].y[1] - env->f[4].y[0]);
		env->f[4].i_max = 25;
		env->f[4].cl[0].h = 30;
		env->f[4].cl[0].s = 1;
		env->f[4].cl[0].l = 1;
		env->curp = 4;
		env->f[4].zml = 0;
		env->f[4].init = 1;
		return ;
	}
	compute(env->f[4], thrd->x, thrd->y);
}
