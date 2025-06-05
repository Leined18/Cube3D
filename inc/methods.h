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


// ==================== Player Management ====================

// ===================== Map Management ====================

t_map   *ft_create_map(const char *path);

// ==================== Game Setup ===================  

int     ft_setup(t_game **game, char *map);
void	ft_handle_exit(void *param);

#endif
