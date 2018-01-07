/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:44:34 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 07:18:15 by tlernoul         ###   ########.fr       */
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

void	zoom_pt(t_frc *edg, int x, int y, int button)
{
	double pr;
	double pi;
	double m;

	if (button == 1 || button == 4)
		m = 1/1.05;
	if (button == 2 || button == 5)
		m = 1.05;
	pr = edg->x[0] + (double)x / edg->zm_x ;
	pi = edg->y[0] + (double)y / edg->zm_y ;
	pr -= pr * m;
	pi -= pi * m;
	edg->x[0] = edg->x[0] * m + pr;
	edg->x[1] = edg->x[1] * m + pr;
	edg->y[0] = edg->y[0] * m + pi;
	edg->y[1] = edg->y[1] * m + pi;
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
