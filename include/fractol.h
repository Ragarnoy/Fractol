/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:26:50 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/05 16:18:57 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_INT 2147483647
# define W_WDTH 700
# define W_HGHT 700
# define FRCTNB 1

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

typedef struct			s_pnt
{
	int					x;
	int					y;
}						t_pnt;

typedef struct			s_frc
{
	double				x[2];
	double				y[2];
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				tmp;
	double				zm_x;
	double				zm_y;
}						t_frc;

typedef struct			s_img
{
	void				*ptr;
	int					*data;
	int					bpp;
	int					l_s;
	int					endian;
}						t_img;

typedef struct			s_env
{
	void				*mlx_p;
	void				*win_p;
	int					cur;
	unsigned int		i_max;
	t_frc				f[3];
	t_img				img;
	t_hsl				pal[37];
}						t_env;

void					put_hslpixel(t_hsl *hsl, t_env *env, t_pnt pt);
int						usage(int error);
t_env					*get_env(void);
t_env					*setup_env(void);
void					palette(t_env *env);
void					redraw(t_env *env);
void					lat_move(t_frc *edg, double x, double y);
int						keyhook(int keycode, void *param);
int						mousehook(int x, int y, void *param);
void					mandelbrot(t_env *env);
void					julia(t_env *env);

#endif
