/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <hherba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:26:04 by hherba            #+#    #+#             */
/*   Updated: 2022/06/15 19:43:52 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_mlx	*z;

	if (ac != 2 || !av[1][0])
	{
		write(1, "./fractol [mandelbrot | julia | burning_ship]\n", 46);
		exit (0);
	}
	z = (t_mlx *) malloc(sizeof(t_mlx));
	if (!z)
		return (1);
	init(z, av[1]);
	if (z->id == 1)
		mandelbrot (z);
	else if (z->id == 2)
		julia (z);
	else if (z->id == 3)
		burning_ship (z);
	mlx_put_image_to_window(z->mlx_ptr, z->win_ptr, z->img_ptr, 0, 0);
	mlx_hook (z->win_ptr, 17, 0, ft_close, z);
	mlx_hook (z->win_ptr, 2, 0, key_press, z);
	mlx_hook (z->win_ptr, 4, 0, mouse_press, z);
	mlx_hook (z->win_ptr, 6, 0, mouse_move, z);
	mlx_loop (z->mlx_ptr);
}
