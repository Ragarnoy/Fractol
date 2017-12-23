/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hslpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:41:17 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/23 17:44:21 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		put_hslpixel(float hue, float saturation, float light)
{
	t_hsl hsl;

	hsl.h = hue;
	hsl.s = saturation;
	hsl.l = light;
	return (ft_hsl_to_rgb(hsl));
}
