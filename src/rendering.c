/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 00:42:37 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 06:14:42 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw(t_env *env)
{
	if (env->cur == 0)
		mandelbrot(env);
	else if (env->cur == 1)
		julia(env);
	else if (env->cur == 2)
		tricorn(env);
}

void	redraw(t_env *env)
{
	ft_bzero(env->img.data, W_WDTH * W_HGHT * 4);
	env->f[env->cur].zm_x = W_WDTH / (env->f[env->cur].x[1] - (env->f[env->cur].x[0]));
	env->f[env->cur].zm_y = W_HGHT / (env->f[env->cur].y[1] - (env->f[env->cur].y[0]));
	draw(env);
	mlx_put_image_to_window(env->mlx_p, env->win_p, env->img.ptr, 0, 0);
}

void	put_hslpixel(t_hsl *hsl, t_env *env, t_pnt pt)
{
	if (!hsl)
	{
		env->img.data[pt.y * W_WDTH + pt.x] = 0;
		return;
	}
	env->img.data[pt.y * W_WDTH + pt.x] = ft_hsl_to_rgb(*hsl) & 0x00FFFFFF;
}
