/*
** mlx_int.h for mlx in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:45:48 2000 Charlie Root
** Last update Wed May 25 16:44:16 2011 Olivier Crouzet
*/



/*
** Internal settings for MiniLibX
*/

#ifndef MLX_INT_H

# define MLX_INT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <X11/XKBlib.h>
// v2 update by X-Keyscore
# include <time.h>
# include <X11/xpm.h>

# define MLX_TYPE_XIMAGE 1

# define MLX_MAX_EVENT LASTEvent


# define ENV_DISPLAY "DISPLAY"
# define LOCALHOST "localhost"
# define ERR_NO_TRUECOLOR "MinilibX Error : No TrueColor Visual available.\n"


typedef	struct	s_xpm_col
{
	int		name;
	int		col;
}				t_xpm_col;


struct	s_col_name
{
	char	*name;
	int		color;
};

typedef struct	s_event_list
{
	int		mask;
	int		(*hook)();
	void	*param;
}				t_event_list;


typedef struct	s_win_list
{
	Window				window;
	GC					gc;
	struct s_win_list	*next;
	int					(*mouse_hook)();
	int					(*key_hook)();
	int					(*expose_hook)();
	void				*mouse_param;
	void				*key_param;
	void				*expose_param;
	t_event_list		hooks[MLX_MAX_EVENT];
}				t_win_list;


typedef struct	s_img
{
	XImage			*image;
	Pixmap			pix;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	// v2 update by X-Keyscore
	int 			shape_use;
	Pixmap			shape_pix;
}				t_img;

typedef struct	s_xvar
{
	Display		*display;
	Window		root;
	int			screen;
	int			depth;
	Visual		*visual;
	Colormap	cmap;
	int			private_cmap;
	t_win_list	*win_list;
	int			(*loop_hook)();
	void		*loop_param;
	int			do_flush;
	int			decrgb[6];
	Atom		wm_delete_window;
	Atom		wm_protocols;
	int 		end_loop;
}				t_xvar;


int				mlx_int_do_nothing();
int				mlx_get_color_value();
int				mlx_int_get_good_color();
int				mlx_int_find_in_pcm();
int				mlx_int_anti_resize_win();
int				mlx_int_wait_first_expose();
int				mlx_int_rgb_conversion();
char			**mlx_int_str_to_wordtab();
void			*mlx_new_image();
int				mlx_int_get_visual(t_xvar *xvar);
int				mlx_int_set_win_event_mask(t_xvar *xvar);
int				mlx_int_str_str_cote(char *str,char *find,int len);
int				mlx_int_str_str(char *str,char *find,int len);


#endif
