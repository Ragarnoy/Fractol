/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:26:50 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/14 02:59:41 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_INT 2147483647
# define W_WDTH 900
# define W_HGHT 900
# define FRCTNB 10
# define THRDNB 16
# define PALNB 11

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

typedef struct			s_range
{
	t_hsl				min;
	t_hsl				max;
}						t_range;

typedef struct			s_flg
{
	int					click;
	int					help;
	int					mouse;
	int					pal;
	int					shift;
	int					rot;
	int					swi;
}						t_flg;

typedef struct			s_frc
{
	int					init;
	t_hsl				cl[2];
	int					zml;
	unsigned int		i_max;
	double				x[2];
	double				y[2];
	double				zm_x;
	double				zm_y;
	double				c_r;
	double				c_i;
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
	int					curp;
	t_frc				f[FRCTNB];
	t_img				img;
	t_range				rnge[PALNB];
	t_flg				flag;
	t_pnt				thrd[8];
}						t_env;

void					putpixel(t_hsl hsl, t_pnt pt);
int						usage(int error);
t_hsl					gethsl(float h, float s, float l);
t_env					*get_env(void);
t_env					*setup_env(void);
void					picker(t_hsl cl, float q, t_pnt pt);
void					palette(t_env *env);
void					draw(t_env *env);
void					redraw(t_env *env);
void					lat_move(t_frc *edg, double x, double y);
void					zoom_in(t_frc *edg, int x, int y);
void					zoom_out(t_frc *edg, int x, int y);
void					click_n_drag(int x, int y, t_frc *edg);
int						keyhook(int keycode, void *param);
int						pointerhook(int x, int y, void *param);
int						mousehook(int button, int x, int y, void *param);
int						releasehook(int button, int x, int y, void *param);
int						shifthook(int keycode, void *param);
void					mandelbrot(t_env *env, t_pnt *thrd);
void					multibrot(t_env *env, t_pnt *thrd);
void					julia(t_env *env, t_pnt *thrd);
void					julia2(t_env *env, t_pnt *thrd);
void					julia3(t_env *env, t_pnt *thrd);
void					tricorn(t_env *env, t_pnt *thrd);
void					bship(t_env *env, t_pnt *thrd);
void					newton(t_env *env, t_pnt *thrd);
void					newton2(t_env *env, t_pnt *thrd);
void					newton3(t_env *env, t_pnt *thrd);
void					variants(t_env *env, t_pnt *thrd);
void					exitprog(void);

#endif
