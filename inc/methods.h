/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:22:07 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/08 10:59:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODS_H
# define METHODS_H

# include "libft.h"
# include "MLX42.h"
# include "types.h"

// ==================== Memory Management ====================
void		ft_cleanup(t_game *game);
void		ft_cleanup_player(t_player *player);
void		ft_cleanup_render(t_render *render);
void		ft_cleanup_map(t_map *map);

// ==================== Parsing ====================
int			parse_file(char *map_name, t_game *game);
int			free_all(t_game *game, char **tokens, char *message);
char		*remove_spaces(char *str);
bool		is_reserved_symbol(char c);
int			is_player_inline(char *line);
int			is_map_line(t_textures *tx, char *line);
int			is_wall_elem(t_game *g, char c);

// ==================== Render Management ====================

void		ft_render_frame(void *param);
void		ft_update_minimap(mlx_t *mlx, t_map *map, t_player *player);

// ==================== Doors Management ====================
int			init_doors(t_map *map, t_doors *d_inf);
int			is_door_symbol(char c);
bool		is_door_open(t_game *g, int x, int y);
t_door		*find_door(t_game *g, int x, int y);
void		update_doors_touch_timer(t_game *g);
void		update_doors_animation(t_game *g, double delta_time);
void		toggle_door(t_door *door);

// ===================== Map Management ====================
int			ft_set_map(t_map *map);
char		**ft_load_map(const char *path, size_t *width, size_t *height);
void		ft_cleanup_map(t_map *map);
void		check_arg_cub(char *name);
int			check_map(t_game *g);
int			generate_map_array(t_game *g);

// ==================== Texture Management ====================
int			ft_load_texture(t_game *g, t_textures *texture);
int			get_texture_direction(int side, t_vect2 ray_dir);
double		calc_wallx(t_game *g, t_ray *ray);
void		calc_wallx_and_texx(t_game *g, t_ray *ray);
void		calc_step_and_pos(double *step, double *pos, t_ray *r, int lineheight);
int			calc_tex_inf(t_game *g, t_ray *ray);


// ==================== Hooks Management ====================
void		ft_on_keypress(mlx_key_data_t keydata, void *param);
void		ft_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod, void* p);
void		ft_on_game_loop(void *param);
void		update_player_movement(t_game *g, double moveSpeed, double rotSpeed);
void		update_mouse_rotation(t_game *g, double rotSpeed);
void		process_scape_key(t_game *g);
void		process_action_key(t_game *g);
// ==================== Game Management ====================

// ==================== Minimap Management ====================

char		ft_get_map_tile(int x, int y);
void		ft_set_pixel(mlx_image_t *img, int x, int y, uint32_t color);

// ==================== Player Movements ====================
void		rotate_player(t_game *game, double angle);
void		move_player_forward(t_game *game, double moveSpeed);
void		move_player_backward(t_game *game, double moveSpeed);
void		strafe_player_left(t_game *game, double moveSpeed);
void		strafe_player_right(t_game *game, double moveSpeed);

// ==================== Raycasting ====================
int			cast_all_rays(t_game *g);
// ==================== Ray Management ====================
int			ft_raycast_dda(t_ray *ray, t_game *g);
int			ft_set_ray(t_ray *ray, int x, t_game *g);

// ==================== Ray Calculation ====================
double		calc_cameraX(int x);
t_vect2		calc_ray_dir(t_vect2 dir, t_vect2 plane, double cameraX);
void		set_ray_pos(t_ray *ray, int x, int y);
void		calc_delta_dist(t_ray *ray);
void		calc_step_dir(t_ray *ray);
void		calc_side_dist(t_ray *ray, t_vect2 *player_pos);
// ==================== Ray Drawing ====================

void		calc_draw_line(t_game *g, t_ray *ray);
void		draw_vertical_line(t_game *g, int x, t_ray *ray, t_tex_inf *tinf);

// ==================== Drawing ====================

void		draw_ceiling(mlx_image_t *img, int x, t_screenline draw);
void		draw_floor(mlx_image_t *img, int x, t_screenline draw);
void		draw_wall(mlx_image_t* img, int x, t_ray *r, t_tex_inf *ti);
// void		draw_minimap(mlx_image_t *img, t_map *map, t_player *player);

// ===================== Calculation ====================


// ==================== Drawing Colors ====================

uint32_t	get_ceiling_color(t_screenline *draw);
uint32_t	get_floor_color(t_screenline *draw);

// ==================== Pixel Management ====================
void		set_color_texture(t_screenline *d, int side, t_tex_inf *ti);

// ==================== Utils ====================
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_clamp(int value, int min, int max);
float		ft_lerp(float a, float b, float t); // linear interpolation
int			sign(double x);
int			ft_pmatch_str(const char *s1, const char *s2, size_t n);
double		ft_get_time(void);

// ==================== Player Calculation ====================
double		ft_calc_fov_factor(double fov_degrees);
t_vect2		ft_calc_player_dir(char dir);
t_vect2		ft_calc_plane(t_vect2 dir, double fov_factor);
int			is_player(char c);
int			is_wall(t_game *g, double x, double y);
void		ft_init_player(t_player *player, t_map *map);
void		can_walk(t_game *game, double new_x, double new_y, t_vect2 dir);

// ==================== Transformations ====================
double		deg_to_rad(double degrees);
void		rotate_vector(t_vect2 *vect, double angle);
t_vect2		normalize(t_vect2 vect);
void		remove_newline(char *line);
void		fill_with_spaces(char *dest, const char *src, int width);

// ==================== printer ====================
void		print_game_info(t_game *game);
void		print_game_map(char **map);

// ==================== Files ====================
int			secure_open(char *map_name);
void		secure_close(int fd);
// ==================== Color ====================
uint32_t	set_color_line(t_game *g, t_coord map, int wall_side);
uint32_t	darken_color(uint32_t color);
int			set_surface_color(t_game *g, int s);

// ==================== Game Setup ===================  
int			ft_setup(t_game *game, char *map);

#endif
