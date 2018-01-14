/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:17:52 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/14 02:46:07 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_hsl	hslrange(t_range rnge, float quo)
{
	t_hsl	col;

	col.h = rnge.min.h + ((rnge.max.h - rnge.min.h) * quo);
	col.s = rnge.min.s + ((rnge.max.s - rnge.min.s) * quo);
	col.l = rnge.min.l + ((rnge.max.l - rnge.min.l) * quo);
	return (col);
}

t_hsl			gethsl(float h, float s, float l)
{
	t_hsl	hsl;

	hsl.h = h;
	hsl.s = s;
	hsl.l = l;
	return (hsl);
}

void			picker(t_hsl cl, float quo, t_pnt pt)
{
	t_env	*env;

	env = get_env();
	if (env->curp == PALNB - 1)
		putpixel(cl, pt);
	else
		putpixel(hslrange(env->rnge[env->curp], quo), pt);
}

static void		palette1(t_env *env)
{
	env->rnge[6].min = gethsl(35, 1, 0.50);
	env->rnge[6].max = gethsl(0, 1, 0.15);
	env->rnge[7].min = gethsl(45, 1, 0.5);
	env->rnge[7].max = gethsl(145, 1, 0.5);
	env->rnge[8].min = gethsl(240, 1, 0.1);
	env->rnge[8].max = gethsl(0, 1, 0.4);
	env->rnge[9].min = gethsl(185, 0, 0.1);
	env->rnge[9].max = gethsl(340, 1, 0.9);
}

void			palette(t_env *env)
{
	int		i;

	i = -1;
	env->rnge[0].min = gethsl(288, 1, 0);
	env->rnge[0].max = gethsl(288, 0.8, 0.71);
	env->rnge[1].min = gethsl(151, 1, 0.71);
	env->rnge[1].max = gethsl(347, 1, 0.75);
	env->rnge[2].min = gethsl(0, 1, 0.6);
	env->rnge[2].max = gethsl(5, 1, 0.9);
	env->rnge[3].min = gethsl(40, 1, 0.54);
	env->rnge[3].max = gethsl(0, 1, 0.45);
	env->rnge[4].min = gethsl(200, 1, 0.3);
	env->rnge[4].max = gethsl(245, 1, 0.9);
	env->rnge[5].min = gethsl(85, 1, 0.5);
	env->rnge[5].max = gethsl(185, 1, 0.5);
	palette1(env);
	while (++i < FRCTNB)
	{
		env->f[i].cl[1].h = 42;
		env->f[i].cl[1].s = 1;
		env->f[i].cl[1].l = 0.5;
	}
}
