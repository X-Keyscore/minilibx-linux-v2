/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:36:48 by anraymon          #+#    #+#             */
/*   Updated: 2024/02/04 22:44:21 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void *mlx_xpm_file_to_image(t_xvar *xvar, char *file, int *width, int *height)
{
	XImage *img;
	XImage *shape;
	t_img *img_return;
	GC shape_gc;

	if (!(img_return = malloc(sizeof(*img_return))))
		return ((void *)0);

	if (XpmReadFileToImage(xvar->display, file, &img, &shape, NULL))
		return ((void *)0);

	if (img)
	{
		img_return->image = img;
		img_return->pix = XCreatePixmap(xvar->display, xvar->win_list->window, img->width, img->height, img->depth);
	}
	else
	{
		free(img_return);
		if (shape)
			XDestroyImage(shape);
		return ((void *)0);
	}
	if (shape)
	{
		img_return->shape_use = 1;
		img_return->shape_pix = XCreatePixmap(xvar->display, xvar->win_list->window, img->width, img->height, 1);
		shape_gc = XCreateGC(xvar->display, img_return->shape_pix, 0, NULL);

		XPutImage(xvar->display, img_return->shape_pix, shape_gc, shape, 0, 0, 0, 0, shape->width, shape->height);

		XPutImage(xvar->display, img_return->pix, xvar->win_list->gc, img, 0, 0, 0, 0, img->width, img->height);

		XFreeGC(xvar->display, shape_gc);
		XDestroyImage(shape);
		shape = NULL;
	}
	else
	{
		img_return->shape_use = 0;
		img_return->shape_pix = None;
		XPutImage(xvar->display, img_return->pix, xvar->win_list->gc, img, 0, 0, 0, 0, img->width, img->height);
	}

	img_return->type = MLX_TYPE_XIMAGE;
	img_return->format = XYPixmap;
	img_return->width = img->width;
	img_return->height = img->height;
	img_return->data = NULL;
	img_return->size_line = img->bytes_per_line;
	img_return->bpp = img->bits_per_pixel;
	*width = img->width;
	*height = img->height;
	return (img_return);
}

void *mlx_xpm_to_image(t_xvar *xvar, char **xpm_data, int *width, int *height)
{
	return ((void *)0);
}
