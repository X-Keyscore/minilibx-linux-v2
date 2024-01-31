/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tool_new_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:55 by anraymon          #+#    #+#             */
/*   Updated: 2024/01/31 20:07:03 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_load_image(t_xvar *xvar, t_img *img)
{
	GC img_gc;
	GC shape_gc;
	Pixmap shapeMask;

	img->shape_use = 0;
	img->shape_pix = XCreatePixmap(xvar->display, xvar->win_list->window, img->image->width, img->image->height, 1);
	shape_gc = XCreateGC(xvar->display, img->shape_pix, 0, NULL);
	XSetForeground(xvar->display, shape_gc, 1);
	for (int y = 0; y < img->image->height; y++) {
		for (int x = 0; x < img->image->width; x++) {
			unsigned long pixel = XGetPixel(img->image, x, y);
			if (pixel != 0)
				XDrawPoint(xvar->display, img->shape_pix, shape_gc, x, y);
			else if (!img->shape_use)
				img->shape_use = 1;
		}
	}
	XPutImage(xvar->display, img->pix, xvar->win_list->gc, img->image, 0, 0, 0, 0, img->image->width, img->image->height);

	XFreeGC(xvar->display, shape_gc);
}

void	mlx_pixel_put_image(t_xvar *xvar, t_img *img, int x, int y, int color)
{
	XPutPixel(img->image, x, y, color);
}
