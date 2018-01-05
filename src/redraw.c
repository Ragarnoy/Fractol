/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:50:21 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/04 16:57:37 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	redraw(t_env *env)
{
	ft_bzero(env->img.data, W_WDTH * W_HGHT * 4);
	if (env->cur == 0)
		mandelbrot(env);
	else if (env->cur == 1)
		julia(env);
	mlx_put_image_to_window(env->mlx_p, env->win_p, env->img.ptr, 0, 0);
}
