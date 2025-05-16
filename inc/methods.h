#ifndef MTMETHODS_H
# define MTMETHODS_H

# include "libft.h"
# include "MLX42.h"
# include "types.h"

// ==================== Memory Management ====================
void    cleanup(t_game **game);

// ==================== Game Setup ====================
int     setup(t_game **game, char *map);
void	handle_exit(void *param);

#endif
