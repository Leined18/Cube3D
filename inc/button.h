/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:17:20 by daniel            #+#    #+#             */
/*   Updated: 2025/06/27 14:57:37 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "MLX42.h"
# include "libft.h"
# include "mt.h"

typedef struct s_button {
    int x;
    int y;
    int width, height;
    uint32_t color; // Color of the button
    char *label;
    void (*on_click)(void *);
    void *param;
    mlx_image_t *img; // Optional: to store the button image if needed
} t_button;




#endif /* BUTTON_H */