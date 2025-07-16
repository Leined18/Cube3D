/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:22:07 by danpalac          #+#    #+#             */
/*   Updated: 2025/07/16 12:33:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODS_H
# define METHODS_H

# include "libft.h"
# include "MLX42.h"
# include "types.h"

// ==================== Memory Management =====================

void		ft_cleanup(t_game *game);
void		ft_cleanup_player(t_player *player);
void		ft_cleanup_render(t_render *render);
void		ft_cleanup_map(t_map *map);

// ==================== Parsing ===============================

int			parse_file(char *map_name, t_game *game);
int			free_all(t_game *game, char **tokens, char *message);
char		*remove_spaces(char *str);
bool		is_reserved_symbol(char c);
int			is_player_inline(char *line);
int			is_map_line(t_textures *tx, char *line);
int			is_wall_elem(t_game *g, char c);

// ==================== Texture Management ====================

int			ft_load_texture(t_game *g, t_textures *texture);
int			get_texture_direction(int side, t_vect2 ray_dir);
void		calc_wallx_and_texx(t_game *g, t_ray *ray);
void		calc_step_and_pos(double *step, double *pos, t_ray *r, int lineheight);
int			calc_tex_inf(t_game *g, t_ray *ray);


// ==================== Render Management ====================

void		ft_render_frame(void *param);
void		ft_update_minimap(mlx_t *mlx, t_map *map, t_player *player);

// ==================== Player Management ====================


// ========================== Doors ==========================
t_door	    *find_door(t_game *g, int x, int y);
void		toggle_door(t_door *door);
double      ft_get_time(void);
int	        is_door_symbol(char c);

// ==================== Player Movements ====================

void		rotate_player(t_game *game, double angle);
void		move_player_forward(t_game *game, double moveSpeed);
void		move_player_backward(t_game *game, double moveSpeed);
void		strafe_player_left(t_game *game, double moveSpeed);
void		strafe_player_right(t_game *game, double moveSpeed);

// ==================== Hooks Management ====================

void    ft_on_keypress(mlx_key_data_t keydata, void *param);
void    ft_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod, void* p);
void    ft_on_game_loop(void *param);
void    process_key(t_game *g, mlx_key_data_t keydata);
void    process_scape_key(t_game *g);

// ==================== Update Management ====================

void        update_player_movement(t_game *g, double moveSpeed, double rotSpeed);
void        update_mouse_rotation(t_game *g, double rotSpeed);
void        update_minimap(t_game *g);

// ==================== Button Hooks =========================

void        ft_on_button_click(mlx_key_data_t keydata, void *param);
void        ft_ui_handle_click(t_render *render, int mouse_x, int mouse_y);

// ==================== Button Management ====================

t_button	button_new(t_vect2 c, const char *label, void (*on_click)(void *), u_int32_t color);
void		ft_button_handle_click(t_button *btn, int mouse_x, int mouse_y);
void		ft_draw_button(mlx_t *mlx, t_button *btn);
int         ft_create_buttons(t_render *render);

// ==================== Button Actions =======================

void        ft_show_minimap(void *param);
void		ft_launch_game(void *p);
void		print_exit(void *param);
void        start_game(void *p);

// ==================== Button Removal ====================
void        ft_remove_button(mlx_t *mlx, t_button *btn);
void        ft_remove_all_buttons(mlx_t *mlx, t_render *render);
void        ft_free_all_buttons(mlx_t *mlx, t_render *render);
void        ft_free_button(mlx_t *mlx, t_button *btn);

// ==================== Button Image Management ====================
mlx_image_t *get_button_image(mlx_t *mlx, t_button *btn);

// ===================== Map Management ====================
int			ft_set_map(t_map *map);
char		**ft_load_map(const char *path, size_t *width, size_t *height);
void		ft_cleanup_map(t_map *map);
void		check_arg_cub(char *name);
int			check_map(t_game *g);
int			generate_map_array(t_game *g);


// ==================== Minimap Management ====================

char		ft_get_map_tile(int x, int y);
void		ft_set_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void        ft_set_scale(mlx_image_t *img, float scale);
mlx_image_t *ft_create_minimap_image(mlx_t *mlx, int width, int height);
void        ft_draw_tile(mlx_image_t *img, t_vect2 vtile, size_t size, uint32_t color);
void        ft_draw_player(mlx_image_t *img, t_game *g);
void        ft_draw_player_dir(mlx_image_t *img, t_game *g);
void        ft_draw_minimap(t_minimap *minimap, t_game *g);
t_minimap  ft_create_minimap(t_map *map);

// ==================== Minimap Utils ====================

void        ft_draw_minimap_image(t_minimap *minimap, mlx_t *mlx, t_vect2 minimap_pos);
void        fill_image_color(mlx_image_t *img, uint32_t color);
void        ft_draw_by_tile(char tile, mlx_image_t *img, t_vect2 pos, double scale);
void        ft_draw_line(mlx_image_t *img, t_vect2 start, t_vect2 end, uint32_t color);

// ==================== Raycasting ====================

int			cast_all_rays(t_game *g);


// ==================== Ray Management ====================

int			ft_raycast_dda(t_ray *ray, t_game *g);
int			ft_set_ray(t_ray *ray, int x, t_game *g);
int			ft_setup_ray(t_ray *ray, int x, t_game *g);
int         reach_wall(t_ray *ray, t_game *g);

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


// ==================== Drawing Colors ====================

uint32_t	get_ceiling_color(t_screenline *draw);
uint32_t	get_floor_color(t_screenline *draw);

// ==================== Pixel Management ====================
void		set_color_texture(t_screenline *d, int side, t_tex_inf *ti);

// ==================== Utils ====================

int		    ft_min(int a, int b);
int		    ft_max(int a, int b);
int		    ft_clamp(int value, int min, int max);
double	    ft_clamp_double(double value, double min, double max);
float	    ft_lerp(float a, float b, float t); // linear interpolation
int		    sign(double x);
int         ft_pmatch_str(const char *s1, const char *s2, size_t n);

// ==================== Player Calculation ====================

double		ft_calc_fov_factor(double fov_degrees);
t_vect2		ft_calc_player_dir(char dir);
t_vect2		ft_calc_plane(t_vect2 dir, double fov_factor);
int			is_player(char c);
int			is_wall(t_game *g, double x, double y);
void		ft_init_player(t_player *player, t_map *map);
void		can_walk(t_game *game, double new_x, double new_y, t_vect2 dir);
double	    get_player_speed(mlx_t *mlx);

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

uint32_t	set_color_line(t_game *g, t_vect2 map, int wall_side);
uint32_t	darken_color(uint32_t color);
int			set_surface_color(t_game *g, int s);

// ==================== Game Setup ===================  

int			ft_setup(t_game *game, char *map);

#endif
