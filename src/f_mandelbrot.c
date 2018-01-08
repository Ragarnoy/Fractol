/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:39:36 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/08 21:28:28 by tlernoul         ###   ########.fr       */
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
	mb->i_max = 25;
	mb->cl.h = 250;
	mb->cl.s = 1.0;
	mb->cl.l = 0.5;
	mb->init = 1;
	ft_putendl("initialized mandelbrot");
}

static void	compute(t_hsl pal[], t_frc mb, int y, int y_max)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = y - 1)))
	{
		while (++pt.y < y_max && ((i = -1)))
		{
			mb.c_r = (double)pt.x / mb.zm_x + mb.x[0];
			mb.c_i = (double)pt.y / mb.zm_y + mb.y[0];
			mb.z_r = 0;
			mb.z_i = 0;
			while ((mb.z_r * mb.z_r) + (mb.z_i * mb.z_i)
					< 4 && ++i < mb.i_max)
			{
				mb.tmp = mb.z_r;
				mb.z_r = (mb.z_r * mb.z_r) - (mb.z_i * mb.z_i) + mb.c_r;
				mb.z_i = (2 * mb.z_i * mb.tmp) + mb.c_i;
			}
			if (i == mb.i_max)
				put_hslpixel(pal[COLNB - 1], pt, 2);
			else
				put_hslpixel(gethsl((i % 100) + mb.cl.h, mb.cl.s, mb.cl.l), pt, 0);
		}
	}
}

void		mandelbrot(t_env *env, t_pnt *thrd)
{
	if (!env->f[0].init)
	{
		initialize(&env->f[0]);
		return;
	}
	compute (env->pal[1], env->f[0], thrd->x, thrd->y);
}
