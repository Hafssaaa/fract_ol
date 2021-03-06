/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <hherba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:26:04 by hherba            #+#    #+#             */
/*   Updated: 2022/06/14 00:13:35 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define MY_COLOR1 0x9b9b9b
# define MY_COLOR2 0xE71D36
# define MY_COLOR3 0xE09F3E
# define MY_COLOR4 0x6B5CA5
# define WIN_W 500.
# define WIN_H 500.
# define MAX_ITER 100

typedef struct s_complex{
	double	r;
	double	i;
}t_complex;

typedef struct s_mlx
{
	t_complex			z;
	t_complex			c;
	t_complex			tmp;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_str;
	int					bpp;
	int					l;
	int					endian;
	int					t_x;
	int					t_y;
	int					color;
	int					newcolor;
	int					id;
	int					m_x;
	int					m_y;
	int					max_iter;
	double				r_min;
	double				r_max;
	double				i_min;
	double				i_max;
	double				interp;
}t_mlx;

void	init(t_mlx *z, char *str);
void	mandelbrot(t_mlx *mlx);
int		ft_close(t_mlx *z);
int		key_press(int keycode, t_mlx *z);
int		mouse_press(int button, int x, int y, t_mlx *z);
int		ft_strcmp(const char *s1, const char *s2);
void	my_mlx_pixel_put(int *img_str, int x, int y, int color);
void	julia(t_mlx *mlx);
void	burning_ship(t_mlx *mlx);
int		mouse_move(int x, int y, t_mlx *z);
double	interpolate(double start, double end, double interp);
void	apply_zoom(t_mlx *mlx, int x, int y);
void	ft_clear_img(int *img_str);
#endif
