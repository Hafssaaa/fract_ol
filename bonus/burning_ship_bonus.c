/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <hherba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:26:04 by hherba            #+#    #+#             */
/*   Updated: 2022/06/13 23:32:46 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	burning_ship2(int x, int y, t_mlx *mlx)
{
	int		iteration;

	iteration = 1;
	mlx->c.r = mlx->r_min + (x + mlx->t_x)
		/ WIN_W * (mlx->r_max - mlx->r_min);
	mlx->c.i = mlx->i_min + (y + mlx->t_y)
		/ WIN_H * (mlx->i_max - mlx->i_min);
	mlx->z.r = 0.0;
	mlx->z.i = 0.0;
	mlx->tmp = mlx->z;
	while (mlx->z.r * mlx->z.r + mlx->z.i * mlx->z.i < 4
		&& iteration < mlx->max_iter)
	{
		mlx->tmp.r = fabs(mlx->z.r * mlx->z.r
				- mlx->z.i * mlx->z.i + mlx->c.r);
		mlx->tmp.i = fabs(2 * mlx->z.r * mlx->z.i + mlx->c.i);
		mlx->z = mlx->tmp;
		iteration++;
	}
	return (iteration);
}

void	burning_ship(t_mlx *mlx)
{
	int				x;
	int				y;
	int				iteration;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			iteration = burning_ship2(x, y, mlx);
			if (iteration == mlx->max_iter)
				mlx->color = 0;
			else
				mlx->color = iteration * mlx->newcolor ;
			my_mlx_pixel_put(mlx->img_str, x, y, mlx->color);
			x++;
		}
		y++;
	}
}
