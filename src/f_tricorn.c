/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:40:23 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 17:10:10 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	initialize(t_frc *tc)
{
	tc->x[0] = -1.8;
	tc->x[1] = 0.9;
	tc->y[0] = -1.2;
	tc->y[1] = 1.2;
	tc->zm_x = W_WDTH / (tc->x[1] - tc->x[0]);
	tc->zm_y = W_HGHT / (tc->y[1] - tc->y[0]);
	tc->i_max = 22;
	tc->init = 1;
	ft_putendl("initialized tricorn");
}

static void	compute(t_env *env, t_frc *tc)
{
	t_pnt			pt;
	unsigned int	i;

	pt.x = -1;
	while (++pt.x < W_WDTH && ((pt.y = -1)))
	{
		while (++pt.y < W_HGHT && ((i = -1)))
		{
			tc->c_r = pt.x / tc->zm_x + tc->x[0];
			tc->c_i = pt.y / tc->zm_y + tc->y[0];
			tc->z_r = 0;
			tc->z_i = 0;
			while ((tc->z_r * tc->z_r) + (tc->z_i * tc->z_i)
					< 4 && ++i < tc->i_max)
			{
				tc->tmp = tc->z_r;
				tc->z_r = (tc->z_r * tc->z_r) - (tc->z_i * tc->z_i) + tc->c_r;
				tc->z_i = (-2 * tc->z_i * tc->tmp) + tc->c_i;
			}
			if (i == tc->i_max)
				env->img.data[pt.y * W_WDTH + pt.x] = 0;
			else
				put_hslpixel(&env->pal[env->flag.pal][i % COLNB], env, pt);
		}
	}
}

void		tricorn(t_env *env)
{
	if (!env->f[2].init)
		initialize(&env->f[2]);
	compute (env, &env->f[2]);
}
