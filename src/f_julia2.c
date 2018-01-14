/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:18:40 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/14 01:49:20 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	calculus(double *c_r, double *c_i, double *z_r, double *z_i)
{
	double tmp;

	tmp = *z_r;
	*z_r = sqrt(*z_r * *z_r) - (*z_i * *z_i) + *c_r;
	*z_i = fabs(2 * *z_i * tmp) + *c_i;
}

static void	compute(t_frc jl, int y, int y_max)
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
			z_r = pt.x / jl.zm_x + jl.x[0];
			z_i = pt.y / jl.zm_y + jl.y[0];
			while ((z_r * z_r) + (z_i * z_i)
					< 8 && ++i < jl.i_max)
				calculus(&jl.c_r, &jl.c_i, &z_r, &z_i);
			if (i == jl.i_max)
				putpixel(jl.cl[0], pt);
			else
				picker(jl.cl[1], (float)i / (float)jl.i_max, pt);
		}
	}
}

void		julia2(t_env *env, t_pnt *thrd)
{
	if (!env->f[8].init)
	{
		env->f[8].x[0] = -1.2;
		env->f[8].x[1] = 1.2;
		env->f[8].y[0] = -1.2;
		env->f[8].y[1] = 1.2;
		env->f[8].zm_x = W_WDTH / (env->f[8].x[1] - env->f[8].x[0]);
		env->f[8].zm_y = W_HGHT / (env->f[8].y[1] - env->f[8].y[0]);
		env->f[8].i_max = 22;
		env->f[8].init = 1;
		env->f[8].cl[0].h = 1.0;
		env->f[8].cl[0].s = 1.0;
		env->f[8].cl[0].l = 0;
		env->curp = 8;
		env->f[8].zml = 0;
		env->f[8].init = 1;
		return ;
	}
	compute(env->f[8], thrd->x, thrd->y);
}
