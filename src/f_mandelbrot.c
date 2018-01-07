/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:39:36 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 06:32:55 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	initialize(t_frc *mb)
{
	mb->x[0] = -2.1;
	mb->x[1] = 0.6;
	mb->y[0] = -1.2;
	mb->y[1] = 1.2;
	mb->zm_x = W_WDTH / (mb->x[1] - mb->x[0]);
	mb->zm_y = W_HGHT / (mb->y[1] - mb->y[0]);
	mb->init = 1;
	ft_putendl("initialized mandelbrot");
}

static void	compute(t_env *env, t_frc *mb)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = -1)))
	{
		while (++pt.y < W_HGHT && ((i = -1)))
		{
			mb->c_r = pt.x / mb->zm_x + mb->x[0];
			mb->c_i = pt.y / mb->zm_y + mb->y[0];
			mb->z_r = 0;
			mb->z_i = 0;
			while ((mb->z_r * mb->z_r) + (mb->z_i * mb->z_i)
					< 4 && ++i < env->i_max)
			{
				mb->tmp = mb->z_r;
				mb->z_r = (mb->z_r * mb->z_r) - (mb->z_i * mb->z_i) + mb->c_r;
				mb->z_i = (2 * mb->z_i * mb->tmp) + mb->c_i;
			}
			if (i == env->i_max)
				put_hslpixel(&env->pal[env->flag.pal][COLNB - 1], env, pt);
			else
				put_hslpixel(&env->pal[env->flag.pal][i % (COLNB - 9)], env, pt);
		}
	}
}

void		mandelbrot(t_env *env)
{
	if (!env->f[0].init)
		initialize(&env->f[0]);
	compute (env, &env->f[0]);
}
