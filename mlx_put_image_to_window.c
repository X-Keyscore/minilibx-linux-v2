/*
** mlx_put_image_to_window.c for MiniLibX in raytraceur
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Mon Aug 14 15:55:49 2000 Charlie Root
** Last update Sun Oct  2 09:53:00 2005 Olivier Crouzet
*/

#include "mlx_int.h"

int mlx_put_image_to_window(t_xvar *xvar, t_win_list *win, t_img *img,
							int x, int y)
{

	if (img->type == MLX_TYPE_SHM)
		XShmPutImage(xvar->display, img->pix, win->gc, img->image, 0, 0, 0, 0,
					 img->width, img->height, False);
	else
	{
		if (img->shape_use)
		{
			XSetClipMask(xvar->display, win->gc, img->shape_pix);
			XSetClipOrigin(xvar->display, win->gc, x, y);
		}
		XCopyArea(xvar->display, img->pix, win->window, win->gc, 0, 0, img->image->width, img->image->height, x, y);
		if (img->shape_use)
		{
			XSetClipMask(xvar->display, win->gc, None);
			XSetClipOrigin(xvar->display, win->gc, 0, 0);
		}
	}
	if (xvar->do_flush)
		XFlush(xvar->display);
}