/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 00:42:37 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/12 21:01:51 by tlernoul         ###   ########.fr       */
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
	else if (env->cur == 3)
		bship(get_env(), thrd);
	else if (env->cur == 4)
		julia2(get_env(), thrd);
	else if (env->cur == 5)
		julia3(get_env(), thrd);
	return (param);
}

static void	help(t_env *env)
{
	intf	i;
	char	*str[9];
	int		col;

	if (env->curp == 0 || env->f[env->cur].cl[1].l < 0.2)
		col = 0xFFFFFFFF;
	else
		col = 0;
	i = 0;
	str[0] = "Help : +/- pour changer la precision";
	str[1] = "PgUp/PgDown pour changer de fractale";
	str[2] = "Shift + Click pour le click-n-drag";
	str[3] = "End pour verrouiller Julia";
	str[4] = "Touches fleches pour bouger";
	str[5] = "Clear pour reset la position";
	str[6] = "'.' pour changer le mode couleur";
	str[7] = "4-1 pour alterer la couleur a tel mode";
	str[8] = "'=' pour activer la rotation de couleur";
	while (i < 9)
	{
		mlx_string_put(env->mlx_p, env->win_p, 8, i * 15 - 1, col, str[i]);
		i++;
	}
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
	if (env->curp > 4)
		env->curp = 1;
	draw(env);
	if (env->flag.help)
		help(env);
}

void		putpixel(t_hsl hsl, t_pnt pt)
{
	get_env()->img.data[pt.y * W_WDTH + pt.x] = ft_hsl_to_rgb(hsl) & 0x00FFFFFF;
}
