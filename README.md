# Unofficial minilibx-linux-v2

The x11 library is really not nice :)
Information

None of the mlx prototypes are affected by this update.

Aucun des prototypes de la mlx n'est affecté par cette mise à jour.
Adding and Optimizations

## Adding:

Added features:

Transparency on `xpm` images is now supported, no colored pixels are anymore displayed.

Ajout de fonctionnalités:

La transparence sur les images `xpm` est maintenant prise en charge, c’est-à-dire que les pixels de couleur none ne sont plus affichés.

## Performance improvements:

The behavior of the `mlx_put_image_to_window()` function has been modified, the rendering speed is now greatly increased.

Amélioration des performances:

Le comportement de la `fonction mlx_put_image_to_window()` a été modifier, la vitesse de rendu est maintenant largement augmentée. Malheureusement la fonction mlx_xpm_file_to_image() est plus lente car elle effectue plus de calcul pour décharger la fonction de rendu.
