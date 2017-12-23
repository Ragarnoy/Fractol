/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:45:30 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/23 20:48:25 by tlernoul         ###   ########.fr       */
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
	/*
	 * Peaufiner structures
	 * isoler mandelbrot
	 * Jouer avec les events
	 * Valeurs butoires
	 * ????????
	 *
	*/
	return (0);
}
