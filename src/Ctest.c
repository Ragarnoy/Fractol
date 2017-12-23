/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ctest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:55:19 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/23 20:02:26 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main()
{
	t_hsl hsl;
	double x1 = -2.1, x2 = 0.6, y1 = -1.2, y2 = 1.2;
	double c_r, c_i, z_r, z_i, tmp;
	x1 *= 1/1.2 ;
	x2 *= 1/1.2 ;
	y1 *= 1/1.2 ;
	y1 *= 1/1.2 ;
	x1 += -1;
	x2 += -1;
	y1 += -1;
	y2 += -1;
	double zoom_x = W_WIDTH/(x2 - x1), zoom_y = W_HEIGHT/(y2 - y1);
	int iteration_max = 100;
	int x, y;
	unsigned int i;
	t_env env;
	env.mlx_p = mlx_init();
	env.win.p = mlx_new_window(env.mlx_p, W_WIDTH, W_HEIGHT, "fractol");
	env.img.ptr = mlx_new_image(env.mlx_p, W_WIDTH, W_HEIGHT);
	env.img.data = (int*)mlx_get_data_addr(env.img.ptr, &env.img.bpp, &env.img.l_s, &env.img.endian);

	hsl.h = 0;
	hsl.s = 1.0;
	hsl.l = 0.5;
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
			if (i < iteration_max)
			{
				hsl.h = hsl.h + 60;
				if (i % 4)
					env.img.data[y * W_WIDTH + x] = put_hslpixel(200, hsl.s, hsl.l);
				else
					env.img.data[y * W_WIDTH + x] = put_hslpixel(100, 0.7, 0.3);
			}
			else if (i == iteration_max)
				env.img.data[y * W_WIDTH + x] = 0;
		}
	}
	mlx_put_image_to_window(env.mlx_p, env.win.p, env.img.ptr, 0, 0);
	mlx_loop(env.mlx_p);
	return (0);
}
