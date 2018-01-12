/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:44:34 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/12 20:38:17 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	lat_move(t_frc *edg, double x, double y)
{
	if (x)
	{
		edg->x[0] += (edg->x[1] - edg->x[0]) * x;
		edg->x[1] += (edg->x[1] - edg->x[0]) * x;
	}
	if (y)
	{
		edg->y[0] += (edg->y[1] - edg->y[0]) * y;
		edg->y[1] += (edg->y[1] - edg->y[0]) * y;
	}
}

void	zoom_in(t_frc *edg, int x, int y)
{
	double pr;
	double pi;
	double m;

	m = 1 / 1.25;
	get_env()->f[get_env()->cur].i_max += 3;
	pr = edg->x[0] + (double)x / edg->zm_x;
	pi = edg->y[0] + (double)y / edg->zm_y;
	pr -= pr * m;
	pi -= pi * m;
	if (((edg->x[0] * m) + pr != edg->x[1] * m + pr) &&
			(edg->y[0] * m + pi != edg->y[1] * m + pi))
	{
		edg->x[0] = edg->x[0] * m + pr;
		edg->x[1] = edg->x[1] * m + pr;
		edg->y[0] = edg->y[0] * m + pi;
		edg->y[1] = edg->y[1] * m + pi;
		get_env()->f[get_env()->cur].zm_x = (double)W_WDTH /
		(get_env()->f[get_env()->cur].x[1] - get_env()->f[get_env()->cur].x[0]);
		get_env()->f[get_env()->cur].zm_y = (double)W_HGHT /
		(get_env()->f[get_env()->cur].y[1] - get_env()->f[get_env()->cur].y[0]);
	}
	redraw(get_env());
}

void	zoom_out(t_frc *edg, int x, int y)
{
	double pr;
	double pi;
	double m;

	m = 1.25;
	get_env()->f[get_env()->cur].i_max -= 3;
	pr = edg->x[0] + (double)x / edg->zm_x;
	pi = edg->y[0] + (double)y / edg->zm_y;
	pr -= pr * m;
	pi -= pi * m;
	if (((edg->x[0] * m) + pr != edg->x[1] * m + pr) &&
			(edg->y[0] * m + pi != edg->y[1] * m + pi))
	{
		edg->x[0] = edg->x[0] * m + pr;
		edg->x[1] = edg->x[1] * m + pr;
		edg->y[0] = edg->y[0] * m + pi;
		edg->y[1] = edg->y[1] * m + pi;
		get_env()->f[get_env()->cur].zm_x = (double)W_WDTH /
		(get_env()->f[get_env()->cur].x[1] - get_env()->f[get_env()->cur].x[0]);
		get_env()->f[get_env()->cur].zm_y = (double)W_HGHT /
		(get_env()->f[get_env()->cur].y[1] - get_env()->f[get_env()->cur].y[0]);
	}
	redraw(get_env());
}

void	click_n_drag(int x, int y, t_frc *edg)
{
	double decal_x;
	double decal_y;

	if (edg->tmp_x)
	{
		decal_x = edg->tmp_x - (edg->x[0] + x / edg->zm_x);
		decal_y = edg->tmp_y - (edg->y[0] + y / edg->zm_y);
		edg->x[0] += decal_x;
		edg->x[1] += decal_x;
		edg->y[0] += decal_y;
		edg->y[1] += decal_y;
	}
	edg->tmp_x = edg->x[0] + x / edg->zm_x;
	edg->tmp_y = edg->y[0] + y / edg->zm_y;
	redraw(get_env());
}
