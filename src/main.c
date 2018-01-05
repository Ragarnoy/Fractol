/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:45:30 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/05 18:50:25 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		usage(int error)
{
	if (error == 0)
		ft_putendl("usage : fractol mandelbrot");
	else if (error == 1)
		perror("fractol");
	exit (-1);
}

int main(int argc, const char *argv[])
{
	t_env *env;
	if (argc != 2 || !argv[1])
		return(usage(0));
	env = setup_env();
	env->cur = 0;
	env->i_max = 40;
	mandelbrot(env);
	mlx_put_image_to_window(env->mlx_p, env->win_p, env->img.ptr, 0, 0);
	mlx_hook(env->win_p, 2, 2, keyhook, env);
	mlx_hook(env->win_p, 6, (1L << 6), mousehook, env);
	mlx_hook(env->win_p, 6, (1L << 2), mousehook, env);
	mlx_loop(env->mlx_p);
	return (0);
}

	/*x1 *= 1/1.2 ;
	x2 *= 1/1.2 ;
	y1 *= 1/1.2 ;
	y1 *= 1/1.2 ;
	x1 += -1;
	x2 += -1;
	y1 += -1;
	y2 += -1;*/
