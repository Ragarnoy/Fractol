/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 00:42:37 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 21:10:27 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		multithread(t_env *env)
{
	pthread_t	thread[8];


}

static void	help(t_env *env)
{
	int		i;
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
	if (env->cur == 0)
		mandelbrot(env);
	else if (env->cur == 1)
		julia(env);
	else if (env->cur == 2)
		tricorn(env);
}

void		redraw(t_env *env)
{
	ft_bzero(env->img.data, W_WDTH * W_HGHT * 4);
//	printf("1ZM = %Lf:%Lf\n", env->f[env->cur].zm_x, env->f[env->cur].zm_y);
//	printf("1CD = %Lf:%Lf || %Lf:%Lf = ", env->f[env->cur].x[0], env->f[env->cur].x[1], env->f[env->cur].y[0], env->f[env->cur].y[1]);
//	printf("xd = %Lf | yd = %Lf\n\n", env->f[env->cur].x[1] - env->f[env->cur].x[0], env->f[env->cur].y[1] - env->f[env->cur].y[0]);
	env->f[env->cur].zm_x = W_WDTH / (env->f[env->cur].x[1] - env->f[env->cur].x[0]);
	env->f[env->cur].zm_y = W_HGHT / (env->f[env->cur].y[1] - env->f[env->cur].y[0]);
//	printf("2ZM = %Lf:%Lf\n", env->f[env->cur].zm_x, env->f[env->cur].zm_y);
//	printf("2CD = %Lf:%Lf || %Lf:%Lf\n", env->f[env->cur].x[0], env->f[env->cur].x[1], env->f[env->cur].y[0], env->f[env->cur].y[1]);
//	ft_putendl("________________________________________________________________________________________________________");
	draw(env);
	mlx_put_image_to_window(env->mlx_p, env->win_p, env->img.ptr, 0, 0);
	if (env->flag.help)
		help(env);
}

void		put_hslpixel(t_hsl *hsl, t_env *env, t_pnt pt)
{
	if (!hsl)
	{
		env->img.data[pt.y * W_WDTH + pt.x] = 0;
		return;
	}
	env->img.data[pt.y * W_WDTH + pt.x] = ft_hsl_to_rgb(*hsl) & 0x00FFFFFF;
}
