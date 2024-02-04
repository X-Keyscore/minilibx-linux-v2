/*
** mlx_destroy_image.c for MinilibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Tue Mar 12 10:25:15 2002 Charlie Root
** Last update Tue May 15 16:45:54 2007 Olivier Crouzet
*/

#include "mlx_int.h"

// v2 update by X-Keyscore
int mlx_destroy_image(t_xvar *xvar, t_img *img)
{
	XDestroyImage(img->image);
	img->image = NULL;
	if (xvar->display != NULL && img->pix != None)
	{
		XFreePixmap(xvar->display, img->pix);
		img->pix = None;
	}
	if (xvar->display != NULL && img->shape_pix != None)
	{
		XFreePixmap(xvar->display, img->shape_pix);
		img->shape_pix = None;
	}
	free(img);
	img = NULL;
	if (xvar->do_flush)
		XFlush(xvar->display);
}
