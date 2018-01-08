/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:40:23 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/08 21:14:16 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	initialize(t_frc *tc)
{
	tc->x[0] = -1.68;
	tc->x[1] = 1.30;
	tc->y[0] = -1.2;
	tc->y[1] = 1.2;
	tc->zm_x = W_WDTH / (tc->x[1] - tc->x[0]);
	tc->zm_y = W_HGHT / (tc->y[1] - tc->y[0]);
	tc->i_max = 22;
	tc->init = 1;
	ft_putendl("initialized tricorn");
}

static void	compute(t_hsl pal[], t_frc tc, int y, int y_max)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = y - 1)))
	{
		while (++pt.y < y_max && ((i = -1)))
		{
			tc.c_r = pt.x / tc.zm_x + tc.x[0];
			tc.c_i = pt.y / tc.zm_y + tc.y[0];
			tc.z_r = 0;
			tc.z_i = 0;
			while ((tc.z_r * tc.z_r) + (tc.z_i * tc.z_i)
					< 4 && ++i < tc.i_max)
			{
				tc.tmp = tc.z_r;
				tc.z_r = (tc.z_r * tc.z_r) - (tc.z_i * tc.z_i) + tc.c_r;
				tc.z_i = (-2 * tc.z_i * tc.tmp) + tc.c_i;
			}
			if (i == tc.i_max)
				put_hslpixel(pal[COLNB - 1], pt, 2);
			else
				put_hslpixel(gethsl((i % 100) + 259, 1, 0.4), pt, 0);
		}
	}
}

void		tricorn(t_env *env, t_pnt *thrd)
{
	if (!env->f[2].init)
	{
		initialize(&env->f[2]);
		return;
	}
	compute (env->pal[0], env->f[2], thrd->x, thrd->y);
}
