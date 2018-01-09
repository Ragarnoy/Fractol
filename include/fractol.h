/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:26:50 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/10 00:28:08 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_INT 2147483647
# define W_WDTH 700
# define W_HGHT 700
# define FRCTNB 2
# define PALNB 4
# define COLNB 15
# define intf uint_fast8_t

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <pthread.h>

typedef struct			s_pnt
{
	int					x;
	int					y;
}						t_pnt;

typedef struct			s_flg
{
	int					click;
	int					help;
	int					mouse;
	int					pal;
	int					shift;
	int					rot;
}						t_flg;

typedef struct			s_frc
{
	int					init;
	t_hsl				cl;
	unsigned int		i_max;
	double				x[2];
	double				y[2];
	double				zm_x;
	double				zm_y;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				tmp;
	double				tmp_x;
	double				tmp_y;
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
	t_frc				f[3];
	t_img				img;
	t_hsl				pal[PALNB][COLNB];
	t_flg				flag;
	t_pnt				thrd[8];
}						t_env;

void					put_hslpixel(t_hsl hsl, t_pnt pt, int spec);
int						usage(int error);
t_hsl					gethsl(float h, float s, float l);
t_hsl					hslrange(t_hsl min, t_hsl max, float quo);
t_env					*get_env(void);
t_env					*setup_env(void);
void					palette(t_env *env);
void					draw(t_env *env);
void					redraw(t_env *env);
void					lat_move(t_frc *edg, double x, double y);
void					zoom_pt(t_frc *edg, int x, int y, int button);
void					click_n_drag(int x, int y, t_frc *edg);
int						keyhook(int keycode, void *param);
int						pointerhook(int x, int y, void *param);
int						mousehook(int button, int x, int y, void *param);
int						releasehook(int button, int x, int y, void *param);
int						shifthook(int keycode, void *param);
void					mandelbrot(t_env *env, t_pnt *thrd);
void					julia(t_env *env, t_pnt *thrd);
void					tricorn(t_env *env, t_pnt *thrd);

#endif
