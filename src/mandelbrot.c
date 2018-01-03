/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:55:34 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/03 20:36:42 by tlernoul         ###   ########.fr       */
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
					< 4 && ++i < mb->i_max)
			{
				mb->tmp = mb->z_r;
				mb->z_r = (mb->z_r * mb->z_r) - (mb->z_i * mb->z_i) + mb->c_r;
				mb->z_i = (2 * mb->z_i * mb->tmp) + mb->c_i;
			}
			if (i == mb->i_max)
				env->img.data[pt.y * W_WDTH + pt.x] = 0;
			else
				put_hslpixel(&env->pal[0], env, pt);
		}
	}
}

void		mandelbrot(t_env *env)
{
	t_frc			mb;

	ft_putendl("mand");
	if (!env->f[0].x[0] || !env->f[0].y[1])
		initialize(&mb);
	mb.i_max = 25;
	compute(env, &mb);
	env->f[0] = mb;
}
