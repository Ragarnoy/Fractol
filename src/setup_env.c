/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:23:01 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/29 22:13:04 by tlernoul         ###   ########.fr       */
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
	return (env);
}

t_env	*setup_env(void)
{
	t_env *env;

	env = get_env();
	return (env);
}
