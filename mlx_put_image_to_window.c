/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:37:37 by anraymon          #+#    #+#             */
/*   Updated: 2024/02/04 22:42:08 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int mlx_put_image_to_window(t_xvar *xvar, t_win_list *win, t_img *img,
							int x, int y)
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
	if (xvar->do_flush)
		XFlush(xvar->display);
}
