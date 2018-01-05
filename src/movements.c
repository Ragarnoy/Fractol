/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:44:34 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/05 18:27:53 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	lat_move(t_frc *edg, double x, double y)
{
	if (x)
	{
		edg->x[0] += x;
		edg->x[1] -= x;
	}
	if (y)
	{
		edg->y[0] += y;
		edg->y[1] -= y;
	}
}

void	zoom_pt(t_frc *edg, int x, int y)
{
	double pr;
	double pi;

	pr = edg->x[0] + (edg->x[1] - edg->x[0]) * (x / W_WDTH);
	pi = edg->y[0] + (edg->y[1] - edg->y[0]) * (y / W_HGHT);
	printf("%f:%f", pr, pi);
}
