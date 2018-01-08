/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 00:42:37 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/08 20:30:51 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	*pick_fract(void *param)
{
	t_pnt *thrd;
	t_env *env;

	env = get_env();
	if (param)
		thrd = (t_pnt*)param;
	if (env->cur == 0)
		mandelbrot(env, thrd);
	else if (env->cur == 1)
		julia(get_env(), thrd);
	else if (env->cur == 2)
		tricorn(get_env(), thrd);
	return (param);
}

static void	help(t_env *env)
{
	intf	i;
	char	*str[5];

	i = -1;
	str[0] = "Help";
	str[1] = "PgUp/PgDown pour changer de fractale";
	str[2] = "Shift + Click pour le click-n-drag";
	str[3] = "Clear pour reset la position";
	str[4] = "End pour verrouiller Julia";
	while (++i < 5)
		mlx_string_put(env->mlx_p, env->win_p, 15, (i + 1) * 15, 0, str[i]);
}

void		draw(t_env *env)
{
	pthread_t	thread[8];
	short		i;

	i = -1;
	if (!env->f[env->cur].init)
		pick_fract(NULL);
	while (++i < 8)
	{
		env->thrd[i].x = i * W_HGHT / 8;
		env->thrd[i].y = (i + 1) * W_HGHT / 8;
	}
	i = -1;
	while (++i < 8)
		pthread_create(&thread[i], NULL, pick_fract, &(env->thrd[i]));
	i = -1;
	while (++i < 8)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(env->mlx_p, env->win_p, env->img.ptr, 0, 0);
}

void		redraw(t_env *env)
{
	ft_bzero(env->img.data, W_WDTH * W_HGHT * 4);
	env->f[env->cur].zm_x = W_WDTH / (env->f[env->cur].x[1] - env->f[env->cur].x[0]);
	env->f[env->cur].zm_y = W_HGHT / (env->f[env->cur].y[1] - env->f[env->cur].y[0]);
	draw(env);
	if (env->flag.help)
		help(env);
}

void		put_hslpixel(t_hsl hsl, t_pnt pt, int spec)
{
	if (spec == 1)
	{
		get_env()->img.data[pt.y * W_WDTH + pt.x] = 0;
		return;
	}
	else if (spec == 2)
	{
		get_env()->img.data[pt.y * W_WDTH + pt.x] = 0xFFFFFF;
		return;
	}
	else
		get_env()->img.data[pt.y * W_WDTH + pt.x] =
							ft_hsl_to_rgb(hsl) & 0x00FFFFFF;
}
