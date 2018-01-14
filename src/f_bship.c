/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_bship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:23:05 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/12 19:34:56 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	calculus(double *c_r, double *c_i, double *z_r, double *z_i)
{
	double tmp;

	tmp = *z_r;
	*z_r = (*z_r * *z_r) - (*z_i * *z_i) + *c_r;
	*z_i = fabs(2 * *z_i * tmp) + *c_i;
}

static void	compute(t_frc bs, int y, int y_max)
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
			bs.c_r = pt.x / bs.zm_x + bs.x[0];
			bs.c_i = pt.y / bs.zm_y + bs.y[0];
			z_r = 0;
			z_i = 0;
			while ((z_r * z_r) + (z_i * z_i)
					< 4 && ++i < bs.i_max)
				calculus(&bs.c_r, &bs.c_i, &z_r, &z_i);
			if (i == bs.i_max)
				putpixel(bs.cl[0], pt);
			else
				picker(bs.cl[1], (float)i / (float)bs.i_max, pt);
		}
	}
}

void		bship(t_env *env, t_pnt *thrd)
{
	if (!env->f[3].init)
	{
		env->f[3].x[0] = -1.68;
		env->f[3].x[1] = 1.30;
		env->f[3].y[0] = -1.2;
		env->f[3].y[1] = 1.2;
		env->f[3].zm_x = W_WDTH / (env->f[3].x[1] - env->f[3].x[0]);
		env->f[3].zm_y = W_HGHT / (env->f[3].y[1] - env->f[3].y[0]);
		env->f[3].i_max = 22;
		env->f[3].cl[0].h = 1;
		env->f[3].cl[0].s = 1.0;
		env->f[3].cl[0].l = 1;
		env->curp = 3;
		env->f[3].init = 1;
		env->f[3].zml = 0;
		return ;
	}
	compute(env->f[3], thrd->x, thrd->y);
}
