/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:52:19 by anraymon          #+#    #+#             */
/*   Updated: 2024/02/06 17:59:48 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
