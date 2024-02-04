/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:55 by anraymon          #+#    #+#             */
/*   Updated: 2024/02/04 20:55:36 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_load_image(t_xvar *xvar, t_img *img)
{
	GC shape_gc;

	img->shape_use = 1;
	img->shape_pix = XCreatePixmap(xvar->display, xvar->win_list->window, img->image->width, img->image->height, 1);
	shape_gc = XCreateGC(xvar->display, img->shape_pix, 0, NULL);
	XSetForeground(xvar->display, shape_gc, 1);
	for (int y = 0; y < img->image->height; y++) {
		for (int x = 0; x < img->image->width; x++) {
			unsigned long pixel = XGetPixel(img->image, x, y);
			if (pixel != 0)
				XDrawPoint(xvar->display, img->shape_pix, shape_gc, x, y);
		}
	}
	XPutImage(xvar->display, img->pix, xvar->win_list->gc, img->image, 0, 0, 0, 0, img->image->width, img->image->height);
	XFreeGC(xvar->display, shape_gc);
}

void	mlx_pixel_put_image(t_xvar *xvar, t_img *img, int x, int y, int color)
{
	XPutPixel(img->image, x, y, color);
}

void	mlx_set_full_screen(t_xvar *xvar, t_win_list *win)
{
    XWindowAttributes windowAttributes;
    XGetWindowAttributes(xvar->display, win->window, &windowAttributes);
    int screen_width = DisplayWidth(xvar->display, DefaultScreen(xvar->display));
    int screen_height = DisplayHeight(xvar->display, DefaultScreen(xvar->display));
    XMoveResizeWindow(xvar->display, win->window, 0, 0, screen_width, screen_height);

}