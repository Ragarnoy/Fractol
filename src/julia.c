/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:37:00 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/03 20:49:31 by tlernoul         ###   ########.fr       */
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
}

static void	compute(t_env *env, t_frc *jl)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = -1)))
	{
		while (++pt.y < W_HGHT && ((i = -1)))
		{
			jl->z_r = pt.x / jl->zm_x + jl->x[0];
			jl->z_i = pt.y / jl->zm_y + jl->y[0];
			jl->c_r = 0.285;
			jl->c_i = 0.01;
			while ((jl->z_r * jl->z_r) + (jl->z_i * jl->z_i)
					< 4 && ++i < jl->i_max)
			{
				jl->tmp = jl->z_r;
				jl->z_r = (jl->z_r * jl->z_r) - (jl->z_i * jl->z_i) + jl->c_r;
				jl->z_i = (2 * jl->z_i * jl->tmp) + jl->c_i;
			}
			if (i == jl->i_max)
				env->img.data[pt.y * W_WDTH + pt.x] = 0;
			else
				put_hslpixel(&env->pal[0], env, pt);
		}
	}
}

void		julia(t_env *env)
{
	t_frc			jl;

	ft_putendl("julia");
	if (!env->f[1].x[0] || !env->f[1].y[1])
		initialize(&jl);
	jl.i_max = 25;
	compute(env, &jl);
	env->f[1] = jl;
}
