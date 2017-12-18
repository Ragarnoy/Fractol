/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ctest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:55:19 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/18 16:47:22 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main()
{
	double x1 = -2.1, x2 = 0.6, y1 = -1.2, y2 = 1.2;
	double c_r, c_i, z_r, z_i, tmp, i;
	double zoom_x = W_WIDTH/(x2 - x1), zoom_y = W_HEIGHT/(y2 - y1);
	int iteration_max = 50;
	int x, y;
	t_env env;
	env.mlx_p = mlx_init();
	env.win.p = mlx_new_window(env.mlx_p, W_WIDTH, W_HEIGHT, "fractol");
	env.img.ptr = mlx_new_image(env.mlx_p, W_WIDTH, W_HEIGHT);
	env.img.data = (int*)mlx_get_data_addr(env.img.ptr, &env.img.bpp, &env.img.l_s, &env.img.endian);
	t_pnt coord;

	x = 0;
	while(x++ < W_WIDTH)
	{
		y = 0;
		while(y++ < W_HEIGHT)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while((z_r * z_r) + (z_i * z_i) < 4 && i < iteration_max)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * z_i * tmp) + c_i;
				i++;
			}
			if (i == iteration_max)
				env.img.data[y * W_WIDTH + x] = 0;
			else
				env.img.data[y * W_WIDTH + x] = color(i);
		}
	}
	mlx_put_image_to_window(env.mlx_p, env.win.p, env.img.ptr, 0, 0);
	mlx_loop(env.mlx_p);
	return (0);
}
