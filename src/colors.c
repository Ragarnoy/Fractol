/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:17:52 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/10 00:32:16 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_hsl		hslrange(t_hsl min, t_hsl max, float quo)
{
	t_hsl range;

	range.h = min.h + ((max.h - min.h) * quo);
	range.s = min.s + ((max.s - min.s) * quo);
	range.l = min.l + ((max.l - min.l) * quo);
	return (range);
}

t_hsl		gethsl(float h, float s, float l)
{
	t_hsl	hsl;

	hsl.h = h;
	hsl.s = s;
	hsl.l = l;
	return(hsl);
}

void static	vaporwave(t_env *env)
{
	int i;

	i = -1;
	while (++i < COLNB)
	{
		if (i < 3)
			env->pal[0][i] = gethsl(347, 1, 0.75);
		else if (i < 6)
			env->pal[0][i] = gethsl(298, 1, 0.74);
		else if (i < 9)
			env->pal[0][i] = gethsl(249, 1, 0.73);
		else if (i < 12)
			env->pal[0][i] = gethsl(200, 1, 0.72);
		else
			env->pal[0][i] = gethsl(151, 1, 0.71);
	}
}

void static	debug(t_env *env)
{
	int i;

	i = -1;
	while(i++ < COLNB)
		env->pal[1][i] = gethsl(i * 24, 1, 0.5);
}

void	palette(t_env *env)
{
	vaporwave(env);
	debug(env);
}
/*
			env->pal[0][i] = gethsl(283, 0.72, 0);
		else if (i < 9)
			env->pal[0][i] = gethsl(157, 1, 0.51);
		else if (i < 12)
			env->pal[0][i] = gethsl(231, 0.68, 0.72);
		else*/
