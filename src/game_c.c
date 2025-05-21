/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:01:13 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 12:47:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void set_camp(t_game **game_p, char *str, va_list ap)
{
    t_game	*game;

    if (!game_p || !str)
        return ;
    game = *game_p;
    if (ft_strncmp(str, "objs", 4) == 0)
        ft_mtadd_back(&game->objs, va_arg(ap, t_mt *), NULL);
    else if (ft_strncmp(str, "map", 3) == 0)
        game->map = va_arg(ap, t_map *);
    else if (ft_strncmp(str, "render", 6) == 0)
        game->render = va_arg(ap, t_render *);
    else if (ft_strncmp(str, "mlx", 3) == 0)
        game->mlx = va_arg(ap, mlx_t *);
    else if (ft_strncmp(str, "player", 6) == 0)
        game->player = va_arg(ap, t_player *);
    else if (ft_strncmp(str, "backup", 6) == 0)
        game->backup = va_arg(ap, t_backup *);
    else
        ft_error("Error: Unknown camp\n", 1);
}


static void set_camps(t_game **game, char *tokens[], va_list ap)
{
    int		i;

    if (!game || !tokens)
        return ;
    i = 0;
    while (tokens[i])
    {
        set_camp(game, tokens[i], ap);
        i++;
    }
}

void *c_game(t_args *args)
{
    if (!args || !args->tokens)
        return (NULL);
    t_game	*game;

    game = ft_calloc(1, sizeof(t_game));
    if (!game)
        return (NULL);
    set_camps(&game, args->tokens, args->ap);
    return (game);
}