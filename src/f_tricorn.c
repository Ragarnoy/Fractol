/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:40:23 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/12 19:35:12 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	calculus(double *c_r, double *c_i, double *z_r, double *z_i)
{
	double tmp;

	tmp = *z_r;
	*z_r = (*z_r * *z_r) - (*z_i * *z_i) + *c_r;
	*z_i = (-2 * *z_i * tmp) + *c_i;
}

static void	compute(t_frc tc, int y, int y_max)
{
	t_pnt			pt;
	unsigned int	i;
	double			z_r;
	double			z_i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = y - 1)))
	{
		while (++pt.y < y_max && ((i = -1)))
		{
			tc.c_r = pt.x / tc.zm_x + tc.x[0];
			tc.c_i = pt.y / tc.zm_y + tc.y[0];
			z_r = 0;
			z_i = 0;
			while ((z_r * z_r) + (z_i * z_i)
					< 4 && ++i < tc.i_max)
				calculus(&tc.c_r, &tc.c_i, &z_r, &z_i);
			if (i == tc.i_max)
				putpixel(tc.cl[0], pt);
			else
				picker(tc.cl[1], (float)i / (float)tc.i_max, pt);
		}
	}
}

void		tricorn(t_env *env, t_pnt *thrd)
{
	if (!env->f[2].init)
	{
		env->f[2].x[0] = -1.91;
		env->f[2].x[1] = 1.21;
		env->f[2].y[0] = -1.54;
		env->f[2].y[1] = 1.45;
		env->f[2].zm_x = W_WDTH / (env->f[2].x[1] - env->f[2].x[0]);
		env->f[2].zm_y = W_HGHT / (env->f[2].y[1] - env->f[2].y[0]);
		env->f[2].i_max = 22;
		env->f[2].cl[0].h = 1;
		env->f[2].cl[0].s = 1.0;
		env->f[2].cl[0].l = 1;
		env->curp = 2;
		env->f[2].zml = 0;
		env->f[2].init = 1;
		return ;
	}
	compute(env->f[2], thrd->x, thrd->y);
}
