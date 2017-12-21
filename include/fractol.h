/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:26:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/21 18:23:16 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_INT 2147483647
# define W_WIDTH 600
# define W_HEIGHT 600

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

typedef struct			s_win
{
	void				*p;
	int					x;
	int					y;
}						t_win;

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
	t_win				win;
	t_img				img;
}						t_env;

#endif
