# Unofficial minilibx-linux-v2

The x11 library is really not nice :)

# FR

# Information

##### Nouveaux prototype

Prototype pour editer un pixel sur une image :
```
void mlx_pixel_put_image(void *mlx_ptr, void *img_ptr, int x, int y, int color);
```

Prototype pour charger l'image avant de l'afficher :
```
void mlx_load_image(void *mlx_ptr, void *img_ptr);
```

Prototype pour relancer mlx_loop (n'oublier pas de rappeler mlx_loop) :
```
void mlx_loop_restart(void *mlx_ptr);
```

##### Prototype modifier

Prototype modifié pour définir la cible de FPS à atteindre :

Ancien ->
```
int mlx_loop(void *mlx_ptr);
```
Modifier ->
```
int mlx_loop(void *mlx_ptr, int target_FPS);
```

# Ajout et optimisations

### Ajout de fonctionnalités

La transparence sur les images `xpm` est maintenant prise en charge, les pixels de couleur none ne sont plus affichés.

### Amélioration des performances

Le comportement de la fonction `mlx_put_image_to_window()` a été modifier, la vitesse de rendu est maintenant largement augmentée. Malheureusement la fonction `mlx_xpm_file_to_image()` est plus lente car elle effectue plus de calcul pour décharger la fonction de rendu.

# EN

# Information

##### New prototype

Prototype for editing a pixel on an image :
```
void mlx_pixel_put_image(void *mlx_ptr, void *img_ptr, int x, int y, int color);
```

Prototype for loading an image before to display :
```
void mlx_load_image(void *mlx_ptr, void *img_ptr);
```

Prototype to restart mlx_loop (don't forget to recall mlx_loop) :
```
void mlx_loop_restart(void *mlx_ptr);
```

##### Prototype edit

Prototype modified to define the FPS target to be achieved :

Old ->
```
int mlx_loop(void *mlx_ptr);
```
Edit ->
```
int mlx_loop(void *mlx_ptr, int target_FPS);
```

# Adding and Optimizations

### Added features

Transparency on `xpm` images is now supported, no colored pixels are anymore displayed.

### Performance improvements

The behavior of the `mlx_put_image_to_window()` function has been modified, the rendering speed is now greatly increased. Unfortunately the `mlx_xpm_file_to_image()` function is slower because it performs more calculations to offload the rendering function.
