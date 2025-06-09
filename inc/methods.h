#ifndef MTMETHODS_H
# define MTMETHODS_H

# include "libft.h"
# include "MLX42.h"
# include "types.h"

// ==================== Memory Management ====================
void    ft_cleanup(t_game **game);
void    ft_cleanup_player(t_player **player);
void    ft_cleanup_render(t_render **render);
void    ft_cleanup_map(t_map **map);

// ==================== Render Management ====================

void    ft_render_frame(void *param);
void    ft_update_minimap(mlx_t *mlx, t_map *map, t_player *player);

// ==================== Player Management ====================

// ===================== Map Management ====================

t_map   *ft_create_map(const char *path);


// ==================== Minimap Management ====================
void    ft_draw_minimap(mlx_t *mlx, t_map *map, t_player *player);
void    ft_draw_tile(mlx_t *mlx, int x, int y, int color);
int     ft_draw_player_on_minimap(mlx_t *mlx, t_player *player);
int     ft_draw_minimap_grid(mlx_t *mlx, t_map *map);
mlx_image_t *ft_create_minimap_image(mlx_t *mlx, t_map *map);
int     ft_create_minimap_viewport(mlx_t *mlx, t_map *map, t_player *player);
char    ft_get_map_tile(int x, int y);
void    ft_set_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void    ft_set_minimap_scale(mlx_image_t *img, float scale);

// ==================== Game Setup ===================  

int     ft_setup(t_game **game, char *map);
void	ft_handle_exit(void *param);

#endif
