/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:17:52 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/12 15:52:57 by tlernoul         ###   ########.fr       */
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

static t_hsl	gethsl(float h, float s, float l)
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
	if (env->curp == FRCTNB)
		putpixel(cl, pt);
	else
		putpixel(hslrange(env->rnge[env->curp], quo), pt);
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
	env->rnge[2].max = gethsl(0, 1, 0.9);
	env->rnge[3].min = gethsl(54, 1, 0.5);
	env->rnge[3].max = gethsl(0, 1, 0.45);
	env->rnge[4].min = gethsl(20, 1, 0.5);
	env->rnge[4].max = gethsl(20, 1, 0.5);
	while (++i < FRCTNB)
	{
		env->f[i].cl[1].h = 42;
		env->f[i].cl[1].s = 1;
		env->f[i].cl[1].l = 0.5;
	}
}
