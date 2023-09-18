/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:54:58 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/17 01:22:38 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//settings
# define CUBE_H	4
# define CUBE_W	4

//window multiplier
# define WM		9
//sens
# define AN		3
# define MS		1.5
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2
# define LA		123
# define RA		124
# define M		46

//FOR WINDOWS
// # define ESC 65307
// # define W	 119
// # define A	 97
// # define S	 115
// # define D	 100
// # define LA	 65361
// # define RA	 65363
// # define M	 109

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_mlximg
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_mlximg;

typedef struct s_xpm
{
	t_mlximg	img;
	int			width;
	int			height;
}	t_xpm;

typedef struct s_map
{
	int		map_width;
	int		map_height;
	void	*img_ptr;
	void	*img_ptr_player;
	int		*addr;
	int		*player_addr;
}	t_map;

typedef struct s_cube
{
	t_map	map_s;
	t_xpm	xpm[4];
	int		xpm_number;
	int		find_pixel;
	int		win_width;
	int		win_height;
	char	**map_file;
	char	**map;
	int		map_long;
	int		map_height;
	void	*mlx;
	void	*win;
	int		*win_addr;
	void	*win_img_ptr;
	double	y;
	double	x;
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	ra;
	bool	la;
	bool	m;
	double	player_x;
	double	player_y;
	double	player_angle;
	double	p_x;
	double	p_y;
	double	ray_x_v;
	double	ray_y_v;
	double	ray_x_h;
	double	ray_y_h;
	double	ray_x;
	double	ray_y;
	double	rx;
	double	ry;
	double	ray_dir_x;
	double	ray_dir_y;
	bool	hit_h;
	bool	hit_v;
	double	vdx;
	double	vdy;
	double	hdx;
	double	hdy;
	double	tmp_x;
	double	tmp_y;
	double	tmp2_x;
	double	tmp2_y;
	int		f_color[3];
	int		c_color[3];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	bool	map_status;
	bool	is_wall;
	double	distance;
}	t_cube;
//////////key//////////
int				key_press(int key, t_cube *cube);
void			handle_keypress(t_cube *cube);
int				key_release(int key, t_cube *cube);
int				mouse_a(int x, int y, t_cube *cube);
//////////check//////////
int				name_chck(char **av);
int				map_init(char **av, t_cube *cube);
int				map_check(t_cube *cube);
void			check_map_size(t_cube *cube);
void			fill_map_spaces(t_cube *cube);
int				is_wall(unsigned int x, unsigned int y, t_cube *cube);
int				is_wall2(double x, double y, t_cube *cube);
double			check_wy(t_cube *cube);
double			check_wx(t_cube *cube);
double			check_sy(t_cube *cube);
double			check_sx(t_cube *cube);
double			check_ax(t_cube *cube);
double			check_ay(t_cube *cube);
double			check_dx(t_cube *cube);
double			check_dy(t_cube *cube);
//////////render//////////
int				render(t_cube *cube);
void			ray_dda(t_cube *cube, double angle, int i);
void			horizontal_while(t_cube *cube, double angle);
double			horizontal(t_cube *cube, double angle);
void			vertical_while(t_cube *cube, double angle);
double			vertical(t_cube *cube, double angle);
//////////init//////////
void			init(t_cube *cube);
void			init_win(t_cube *cube);
void			init_img(t_cube *cube);
void			init_xpm(t_cube *cube);
void			take_texture(t_cube *cube);
void			take_color(t_cube *cube);
void			color_code_init(int *arry, char *str);
//////////draw//////////
void			draw_win(t_cube *cube);
void			draw_img(t_cube *cube);
void			draw_minimap(t_cube *cube);
void			draw_trans_map(t_cube *cube);
void			draw_player(t_cube *cube);
void			draw_ray_and_3d(t_cube *cube);
unsigned long	rgb_to_hex(int transparent, int r, int g, int b);

#endif
