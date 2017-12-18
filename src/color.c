/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:17:52 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/19 00:28:00 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_rgb	getrgb(t_rgb *rgb, float r, float g, float b)
{
	float m;

	m = rgb->l - rgb->c / 2;
	rgb->r = roundf((r + m) * 255);
	rgb->g = roundf((g + m) * 255);
	rgb->b = roundf((b + m) * 255);
	return (*rgb);
}

int		hslto_rgb(t_hsl hsl)
{
	t_rgb	rgb;
	int		color;
	float	x;

	rgb.l = hsl.l;
	hsl.h = hsl.h / 60;
	rgb.c = (1 - fabs((hsl.l * 2) - 1)) * hsl.s;
	x = rgb.c * (1.0 - fabs(fmod(hsl.h, 2.0) - 1.0));
	if (hsl.h >= 0 && hsl.h <= 1)
		rgb = getrgb(&rgb, rgb.c, x, 0);
	if (hsl.h >= 1 && hsl.h <= 2)
		rgb = getrgb(&rgb, x, rgb.c, 0);
	if (hsl.h >= 2 && hsl.h <= 3)
		rgb = getrgb(&rgb, 0, rgb.c, x);
	if (hsl.h >= 3 && hsl.h <= 4)
		rgb = getrgb(&rgb, 0, x, rgb.c);
	if (hsl.h >= 4 && hsl.h <= 5)
		rgb = getrgb(&rgb, x, 0, rgb.c);
	if (hsl.h >= 5 && hsl.h <= 6)
		rgb = getrgb(&rgb, rgb.c, 0, x);
	return ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
}


