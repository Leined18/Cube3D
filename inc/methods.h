/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:22:07 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/02 14:31:11 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODS_H
# define METHODS_H

# include "libft.h"
# include "MLX42.h"
# include "types.h"

// ==================== Memory Management ====================
void    ft_cleanup(t_game *game);
void    ft_cleanup_player(t_player *player);
void    ft_cleanup_render(t_render *render);
void    ft_cleanup_map(t_map *map);

// ==================== Parsing ====================
int     parse_file(char *map_name, t_game *game);
int	    free_all(t_game *game, char **tokens, char *message);
char	*remove_spaces(char *str);

// ==================== Render Management ====================

void    ft_render_frame(void *param);
void    ft_update_minimap(mlx_t *mlx, t_map *map, t_player *player);

// ==================== Player Management ====================

// ===================== Map Management ====================
int         ft_set_map(t_map *map);
char  **ft_load_map(const char *path, size_t *width, size_t *height);
void  ft_cleanup_map(t_map *map);
void wrong_map_exit(char *buffer, char *message, int need_free);
void check_arg_cub(char *name);
void wrong_generate_map_exit(char *message, int fd);
void wrong_copy_map_exit(char **copy_array, int pos);
int		check_map(t_game *g);

// ==================== Texture Management ====================
int     ft_load_texture(t_textures *texture);
void    ft_free_texture(t_textures *texture);
int     ft_init_textures(t_map *map);
int		get_texture_direction(int side, t_vect2 ray_dir);
void	calc_wallx_and_texx(t_game *g, t_ray *ray);
void	calc_step_and_pos(double *step, double *pos, t_ray *r, int lineheight);
void	calc_tex_inf(t_game *g, t_ray *ray);

// ==================== Hooks Management ====================
void    ft_on_destroy(void *param);
void    ft_on_keypress(mlx_key_data_t keydata, void *param);
void    ft_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod, void* p);
void    ft_on_game_loop(void *param);
void    update_player_movement(t_game *g, double moveSpeed, double rotSpeed);
void    update_mouse_rotation(t_game *g, double rotSpeed);
void    process_scape_key(t_game *g);

// ==================== Button Hooks ====================
void    ft_on_button_click(mlx_key_data_t keydata, void *param);
void    ft_ui_handle_click(t_render *render, int mouse_x, int mouse_y);


// ==================== Game Management ====================

// ==================== Button Management ====================

t_button	button_new(t_vect2 c, const char *label, void (*on_click)(void *), u_int32_t color);
void		ft_button_handle_click(t_button *btn, int mouse_x, int mouse_y);
void		ft_draw_button(mlx_t *mlx, t_button *btn);
int         ft_create_buttons(t_render *render);

// ==================== Button Removal ====================
void        ft_remove_button(mlx_t *mlx, t_button *btn);
void        ft_remove_all_buttons(mlx_t *mlx, t_render *render);
void        ft_free_all_buttons(mlx_t *mlx, t_render *render);
void        ft_free_button(mlx_t *mlx, t_button *btn);

// ==================== Button Image Management ====================
mlx_image_t *get_button_image(mlx_t *mlx, t_button *btn);


// ==================== Minimap Management ====================

char    ft_get_map_tile(int x, int y);
void    ft_set_pixel(mlx_image_t *img, int x, int y, uint32_t color);

// ==================== Player Movements ====================
void    rotate_player(t_game *game, double angle);
void    move_player_forward(t_game *game, double moveSpeed);
void    move_player_backward(t_game *game, double moveSpeed);
void    strafe_player_left(t_game *game, double moveSpeed);
void    strafe_player_right(t_game *game, double moveSpeed);

// ==================== Raycasting ====================
void    cast_all_rays(t_game *g);
// ==================== Ray Management ====================
int     ft_raycast_dda(t_ray *ray, t_game *g);
int     ft_set_ray(t_ray *ray, int x, t_game *g);

// ==================== Ray Calculation ====================
double  calc_cameraX(int x);
t_vect2 calc_ray_dir(t_vect2 dir, t_vect2 plane, double cameraX);
void    set_ray_pos(t_ray *ray, int x, int y);
void    calc_delta_dist(t_ray *ray);
void    calc_step_dir(t_ray *ray);
void    calc_side_dist(t_ray *ray, t_vect2 *player_pos);
// ==================== Ray Drawing ====================

void    calc_draw_line(t_game *g, t_ray *ray);
//void    draw_vertical_line(mlx_image_t *img, int x, t_screenline draw, bool dark_mode);
void	draw_vertical_line(t_game *g, int x, t_screenline d, t_tex_inf *ti);

// ==================== Drawing ====================

void    draw_ceiling(mlx_image_t *img, int x, t_screenline draw);
void    draw_floor(mlx_image_t *img, int x, t_screenline draw);
void	draw_wall(mlx_image_t* img, int x, t_screenline *d, t_tex_inf *ti);
// void    draw_wall(mlx_image_t *img, int x, t_screenline draw, bool dark_mode);
// void    draw_minimap(mlx_image_t *img, t_map *map, t_player *player);
// ===================== Calculation ====================
// double     calc_texture_y(int y, int start, int height, int texture_height);

// ==================== Drawing Colors ====================

uint32_t	get_ceiling_color(t_screenline *draw);
uint32_t	get_floor_color(t_screenline *draw);
// uint32_t	get_wall_color(t_screenline *draw, int y);

// ==================== Pixel Management ====================
// uint32_t    get_pixel_img(mlx_image_t *img, int x, int y);
// uint32_t    get_pixel_texture(mlx_texture_t *texture, int x, int y);
void	set_color_texture(t_screenline *d, t_tex_inf *ti);

// ==================== Utils ====================
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_clamp(int value, int min, int max);
float	ft_lerp(float a, float b, float t); // linear interpolation
int		sign(double x);




// button actions
void		ft_launch_game(void *p);
void		print_exit(void *param);
void        start_game(void *p);

// ==================== Player Calculation ====================
double	ft_calc_fov_factor(double fov_degrees);
t_vect2	ft_calc_player_dir(char dir);
t_vect2	ft_calc_plane(t_vect2 dir, double fov_factor);
int		is_player(char c);
int		is_wall(t_game *g, double x, double y);
void	ft_init_player(t_player *player, t_map *map);
void	can_walk(t_game *game, double new_x, double new_y, t_vect2 dir);

// ==================== Transformations ====================
double		deg_to_rad(double degrees);
void		rotate_vector(t_vect2 *vect, double angle);
t_vect2	normalize(t_vect2 vect);
void		remove_newline(char *line);
void		fill_with_spaces(char *dest, const char *src, int width);

// ==================== printer ====================
void		print_game_info(t_game *game);
void		print_game_map(char **map);
// ==================== Checkers ====================
int		dir_ok(char *dir);
// ==================== Files ====================
int		secure_open(char *map_name);
void	secure_close(int fd);
// ==================== Color ====================
uint32_t	set_color_line(t_game *g, t_vect2 map, int wall_side);
uint32_t	darken_color(uint32_t color);
int			set_surface_color(t_game *g, char surface);

// ==================== Game Setup ===================  
int     ft_setup(t_game *game, char *map);
void	ft_handle_exit(void *param);

#endif
