# Unofficial minilibx-linux-v2

The x11 library is really not nice :)

# Information

##### * Deux nouveaux prototype et un modifier :

Utilser ce prototype pour editer un pixel sur une image :
```
void mlx_pixel_put_image(void *mlx_ptr, void *img_ptr, int x, int y, int color);
```

Utiliser ce prototype pour charger l'image avant de l'afficher :
```
void mlx_load_image(void *mlx_ptr, void *img_ptr);
```

Prototype modifié pour définir la cible de FPS à atteindre :
```
int mlx_loop(void *mlx_ptr, int target_FPS);
```

##### * Two new prototype :

Use this prototype for editing a pixel on an image :
```
void mlx_pixel_put_image(void *mlx_ptr, void *img_ptr, int x, int y, int color);
```

Use this prototye for loading an image before to display :
```
void mlx_load_image(void *mlx_ptr, void *img_ptr);
```

Prototype modified to define the FPS target to be achieved :
```
int mlx_loop(void *mlx_ptr, int target_FPS);
```

# Adding and Optimizations

### Added features:

Transparency on `xpm` images is now supported, no colored pixels are anymore displayed.

### Ajout de fonctionnalités:

La transparence sur les images `xpm` est maintenant prise en charge, les pixels de couleur none ne sont plus affichés.

### Performance improvements:

The behavior of the `mlx_put_image_to_window()` function has been modified, the rendering speed is now greatly increased. Unfortunately the `mlx_xpm_file_to_image()` function is slower because it performs more calculations to offload the rendering function.

### Amélioration des performances:

Le comportement de la fonction `mlx_put_image_to_window()` a été modifier, la vitesse de rendu est maintenant largement augmentée. Malheureusement la fonction `mlx_xpm_file_to_image()` est plus lente car elle effectue plus de calcul pour décharger la fonction de rendu.
