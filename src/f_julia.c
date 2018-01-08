/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:37:00 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/08 21:12:03 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	initialize(t_frc *jl)
{
	jl->x[0] = -1;
	jl->x[1] = 1;
	jl->y[0] = -1.2;
	jl->y[1] = 1.2;
	jl->zm_x = W_WDTH / (jl->x[1] - jl->x[0]);
	jl->zm_y = W_HGHT / (jl->y[1] - jl->y[0]);
	jl->i_max = 22;
	jl->init = 1;
	ft_putendl("initialized julia");
}

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
				put_hslpixel(gethsl((i % 100) + 259, 1, 0.4), pt, 0);
		}
	}
}

void		julia(t_env *env, t_pnt *thrd)
{
	if (!env->f[1].init)
	{
		initialize(&env->f[1]);
		return;
	}
	compute (env->pal[0], env->f[1], thrd->x, thrd->y);
}
