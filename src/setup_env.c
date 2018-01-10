/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:23:01 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/10 23:00:21 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env	*get_env(void)
{
	static t_env	*env = NULL;

	if (env)
		return (env);
	if (!(env = malloc(sizeof(t_env))))
		return (NULL);
	if (!(env->mlx_p = mlx_init()))
		return (NULL);
	if (!(env->win_p = mlx_new_window(env->mlx_p, W_WDTH, W_HGHT, "fractol")))
		return (NULL);
	return (env);
}

t_env	*setup_env(void)
{
	t_env	*env;
	int		i;

	i = -1;
	if (!(env = get_env()))
		usage(1);
	while (i++ < FRCTNB)
		ft_bzero(&env->f[i], sizeof(t_frc));
	palette(env);
	env->flag.pal = 0;
	env->flag.mouse = 1;
	env->flag.help = 0;
	env->flag.shift = 0;
	env->flag.click = 0;
	env->flag.rot = 0;
	env->flag.swi = 0;
	env->img.ptr = mlx_new_image(env->mlx_p, W_WDTH, W_HGHT);
	env->img.data = (int*)mlx_get_data_addr(env->img.ptr, &env->img.bpp,
					&env->img.l_s, &env->img.endian);
	return (env);
}
