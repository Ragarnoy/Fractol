/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hslpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:41:17 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/03 18:24:36 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_hslpixel(t_hsl *hsl, t_env *env, t_pnt pt)
{
	if (!hsl)
	{
		env->img.data[pt.y * W_WDTH + pt.x] = 0;
		return;
	}
	env->img.data[pt.y * W_WDTH + pt.x] = ft_hsl_to_rgb(*hsl);
}
