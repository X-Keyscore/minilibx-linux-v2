/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:06:23 by anraymon          #+#    #+#             */
/*   Updated: 2024/01/31 20:06:32 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void *mlx_int_new_image(t_xvar *xvar, int width, int height, int format)
{
	t_img *img;

	if (!(img = malloc(sizeof(*img))))
		return ((void *)0);
	if (!(img->data = malloc((width + 32) * height * 4)))
	{
		free(img);
		return ((void *)0);
	}
	bzero(img->data, (width + 32) * height * 4);
	img->image = XCreateImage(xvar->display, xvar->visual, xvar->depth, format, 0,
							  img->data, width, height, 32, 0);
	if (!img->image)
	{
		free(img->data);
		free(img);
		return ((void *)0);
	}
	img->shape_use = 0;
	img->gc = 0;
	img->size_line = img->image->bytes_per_line;
	img->bpp = img->image->bits_per_pixel;
	img->width = width;
	img->height = height;
	img->pix = XCreatePixmap(xvar->display, xvar->win_list->window, img->image->width, img->image->height, img->image->depth);
	img->format = format;
	img->type = MLX_TYPE_XIMAGE;
	if (xvar->do_flush)
		XFlush(xvar->display);
	return (img);
}

void *mlx_new_image(t_xvar *xvar, int width, int height)
{
	return (mlx_int_new_image(xvar, width, height, XYPixmap));
}