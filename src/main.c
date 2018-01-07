/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:45:30 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 07:23:40 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			usage(int error)
{
	if (error == 0)
		ft_putendl("usage : fractol mandelbrot");
	else if (error == 1)
		perror("fractol");
	else if (error == 2)
		ft_putendl("invalid fractal");
	exit (-1);
}

int static	parse(const char *str)
{
	if (!ft_strcmp(str, "mandelbrot"))
		return (0);
	else if (!ft_strcmp(str, "julia"))
		return (1);
	else if (!ft_strcmp(str, "tricorn"))
		return (2);
	else
		return(usage(2));
}

int			main(int argc, const char *argv[])
{
	t_env *env;
	if (argc != 2 || !argv[1])
		return(usage(0));
	ft_putendl("de la merd");
	env = setup_env();
	env->cur = parse(argv[1]);
	env->i_max = 50;
	draw(env);
	mlx_put_image_to_window(env->mlx_p, env->win_p, env->img.ptr, 0, 0);
	mlx_hook(env->win_p, 2, 2, keyhook, env);
	mlx_hook(env->win_p, 3, 3, shifthook, env);
	mlx_hook(env->win_p, 6, (1L << 6), pointerhook, env);
	mlx_hook(env->win_p, 4, (1L << 2), mousehook, env);
	mlx_hook(env->win_p, 4, (1L << 2), mousehook, env);
	mlx_hook(env->win_p, 5, (1L << 3), releasehook, env);
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
