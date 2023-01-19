/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:00:01 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/19 11:29:00 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "linear_alg/linear_alg.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line_bonus.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>

# define XWIN 2300
# define YWIN 1300
# define ZOOM 1.1
# define TRANSLATION 20
# define ROTANGLE 0.05
# define RATIO 60
# define ZRATIO 2

# define X 0
# define Y 1
# define Z 2

# define THETA 0
# define PHI 1

typedef struct	s_sphere {
	struct nml_mat_s	**sphecs;
	struct nml_mat_s	**polar_cord;
	double				radius;
}				t_sphere;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_dda {
	int		i;
	int		j;
	double 	dx;
	double	dy;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	step;
	double	xinc;
	double	yinc;
}				t_dda;

typedef struct s_fdf {
	int					background;
	void				*mlx;
	void				*win;
	t_data				img;
	t_dda				drawer;
	int					fd;
	int					width;
	int					height;
	int					area;
	int					**map;
	struct nml_mat_s	**vecs;
	t_sphere			sphere;
	struct nml_mat_s	*rotmatz;
	struct nml_mat_s	*rotmatx;
	struct nml_mat_s	*rotmaty;
	struct nml_mat_s	*origin;
	struct nml_mat_s	*i;
	struct nml_mat_s	*j;
	struct nml_mat_s	*k;
	double				angle;
	double				rangle;
	double				A;
	double				B;
	int					color;
} t_fdf;

int 	**map_reader(t_fdf *mats);
void	my_mlx_pixel_put(t_data *data, int xi, int yi, int color);
nml_mat	**vector_maker(t_fdf *mats);
int		rotationz(int keycode, t_fdf *mats);
int		rotationy(int keycode, t_fdf *mats);
int		rotationx(int keycode, t_fdf *mats);
void	rotz_init(t_fdf *mats);
void	rotx_init(t_fdf *mats);
void	roty_init(t_fdf *mats);
int		isoview(int keycode, t_fdf *mats);
int		xview(int keycode, t_fdf *mats);
int		yview(int keycode, t_fdf *mats);
int		translation(int keycode, t_fdf *mats);
int		zoom(int keycode, t_fdf *mats);
void	draw_frame(t_fdf *mats);
void	vector_trans(t_fdf *mats);
void	maps_dims(t_fdf *mats);
void	free_mats(t_fdf *mats);
void 	earth(t_fdf *mats);
void	red_green(t_fdf *mats);
int		colorseve(int keycode,t_fdf *mats);
void	scorched_earth(t_fdf *mats);
void	my_mlx_pixel_put(t_data *data, int xi, int yi, int color);
void	epic_spellbook(t_fdf *mats);
void	print_str(t_fdf *mats, int x, int y, char *str);
void	print_nbr(t_fdf *mats, int x, int y, int nbr);
void 	castelvania(t_fdf *mats);
void	white_back(t_fdf *mats);
void	gimme_grey(t_fdf *mats);
void	sky_high(t_fdf *mats);


#endif

/*
                              ___                     ___              _        __     _       __      _    
    o O O    o O O    o O O  / __|   _  _    _ _     |   \   __ _     | |      / _|   / |     /  \    / |   
   o        o        o      | (_ |  | +| |  | ' \    | |) | / _` |    | |     |  _|   | |    | () |   | |   
  TS__[O]  TS__[O]  TS__[O]  \___|   \_,_|  |_||_|   |___/  \__,_|   _|_|_   _|_|_   _|_|_   _\__/   _|_|_  
 {======| {======| {======|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
./o--000'./o--000'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
*/