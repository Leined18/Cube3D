/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/16 12:05:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# include <stdlib.h>
# include <stdbool.h>

# include "libft.h"
# include "mtstructs.h"
# include "math.h"

#define PI		M_PI
#define TWO_PI	(2 * PI)
#define TAU     (2 * PI)   // vuelta completa

// Direcciones horizontales (en fracciones de vuelta sobre el plano XZ)
// 0.00 = 0° (NORTE = +Z), 0.25 = 90° (ESTE = +X), 0.50 = 180° (SUR = -Z), 0.75 = 270° (OESTE = -X)
#define NORTH   0.00f  // +Z (al frente)
#define EAST    0.25f  // +X (derecha)
#define SOUTH   0.50f  // -Z (atrás)
#define WEST    0.75f  // -X (izquierda)

// Elevación (ángulo vertical en fracción de vuelta)
// 0.00 = -90° (abajo), 0.50 = 0° (plano horizontal), 1.00 = +90° (arriba)
#define DOWN    0.00f  // -Y (bajar)
#define FLAT    0.5f  // horizontal (sin cambio en Y)
#define UP      1.00f  // +Y (subir)

#define DEGREE_NORTH 0.00f
#define DEGREE_EAST 90.00f
#define DEGREE_SOUTH 180.00f
#define DEGREE_WEST 270.00f

#define DEGREE_DOWN -90.00f
#define DEGREE_FLAT 0.00f
#define DEGREE_UP 90.00f


// ==================== Memory Management ====================

void			ft_mtfree(void *mt);
int             ft_mtremove(t_mt **head, t_mt *target, bool free_node);
void			ft_mtdelete(const char *key);
void			ft_mtclear(t_mt **lst);
t_mt			*ft_mtnew(const char *key, const char *id);

// ==================== Count Functions ====================


// ==================== Iteration and Set Functions ====================


// ==================== Movement Functions ====================


// ==================== Deletion Functions ====================


// ==================== Insertion Functions ====================


// ==================== Add Functions ====================

int				ft_mtadd_back(t_mt **node, t_mt *new_node);

// ==================== Backup Functions =======================

size_t			ft_hash(t_mt *key);
size_t          ft_hash_str(const char *str);

// 
t_backup		*ft_backup_new(size_t slot_count);
t_backup		*ft_backup_static(size_t slot_count, bool new, bool clear);

void			ft_backup_add(t_backup **backup, t_mt *node);
void			ft_backup_add_track(t_backup **backup, t_track *track);
void			ft_backup_add_slot(t_backup **backup, t_slot *slot);

int 			ft_backup_clear(t_backup **backup);
void			ft_backup_remove(t_backup **backup, t_mt *target, bool free_target);
void            ft_backup_delete(t_backup **backup, const char *key);



t_mt         *ft_backup_search(t_backup **backup, const char *key);


// ==================== Backup Slot Functions ====================

int 			ft_backup_remove_slot(t_backup **backup, t_mt *target, bool free_slot);
void            ft_backup_slot_update(t_backup **backup, size_t new_slot_count);
void            ft_backup_add_slot_mt(t_backup **backup, t_mt *node);


// ==================== Slot Functions ====================

void            ft_slot_clear(t_slot **slots, size_t slot_count, bool free_data);
t_slot         *ft_slot_search(t_slot *slot, const char *key);
t_slot         *ft_slot_find(t_slot **slots, size_t slot_count, t_slot *target);
int            ft_slot_remove(t_slot **slots, size_t slot_count, t_mt *target, bool free_target);
t_slot         **ft_slot_array_new(size_t slot_count);
void            ft_slot_add_botton(t_slot **slots, t_slot *new_slot);
t_slot         *ft_slot_new(const char *id, const char *group_id, t_mt *node);
void           ft_slot_free(t_slot **slot, bool free_node);
int             ft_slot_add_mt(t_slot ***slot, size_t slot_count, t_mt *node);
void            ft_slot_hash_add(t_slot **slots, size_t slot_count, t_slot *node);
t_mt         *ft_slot_search_mt(t_slot **slots, size_t slot_count, const char *id);
t_slot         *ft_slot_hash_search(t_slot **slots, size_t slot_count, const char *key);



// ==================== Track Functions ====================

t_track		    *ft_track_find(t_track *tracks, t_track *target);
t_track			*ft_track_new(const char *group_id, const char *node_id, t_mt *node);
void			ft_track_clear(t_track **tracks, bool free_data);
void            ft_track_free(t_track **track, bool free_node);
int             ft_track_add_back(t_track **node, t_track *new_node);
t_track         *ft_track_search(t_track *track, const char *key);
int 			ft_track_remove(t_track **tracker, t_track *node, bool free_node);


// ==================== Group Functions ====================

t_group         *ft_group_new(const char *id);
t_group         *ft_group_search(t_group *groups, const char *id);
void            ft_group_add_back(t_group **group, t_group *new_group);
void            ft_group_add_track(t_group **group, t_track *track);
void            ft_group_clear(t_group **group, bool free_data);
void            ft_group_free(t_group **group, bool free_data);
int             ft_group_add_mt(t_group **group, t_mt *node);
t_mt            *ft_group_search_mt(t_group *group, const char *key);




// ==================== Filter Functions ====================


// ==================== Fold Functions ====================

// ==================== Collection Functions ====================

// ==================== Compare Functions ====================

int					ft_mtkeycmp(const t_mt *mt1, const char *key);

// ==================== Search Functions ====================

t_mt				*ft_mtsearch(t_mt *head, const char *key);
t_mt				*ft_mtfind(t_mt *head, t_mt *mt);
t_mt                *ft_mtget(const char *key);

// ==================== Navigation Functions ====================
t_mt				*ft_mtlast(t_mt **node, bool move);


// ==================== Manipulation Functions ====================

// ===================== Getter Functions ====================

char			    *ft_mtget_key(t_mt *mt);
void                *ft_mtget_id(t_mt *mt);
void			    *ft_mtget_data(t_mt *mt);
void			    *ft_mtget_data_free(t_mt *mt);
void			    *ft_mtget_addon(t_mt *mt);
void			    *ft_mtget_addon_free(t_mt *mt);


// ==================== Setter Functions ====================

int                 ft_mtset(const char *key, void *data, void (*set_func)(struct s_mt *, void *));

void			    ft_mtset_key(t_mt *mt, void *key);
void				ft_mtset_id(t_mt *mt, void *id);
void				ft_mtset_data(t_mt *mt, void *data);
void				ft_mtset_data_free(t_mt *mt, void *data_free);

void				ft_mtset_addon(t_mt *mt, void *addon);
void				ft_mtset_addon_free(t_mt *mt, void *addon_free);


int					setter(int (*s_function)(t_args *args), void **s_ref,
                     const char *str, ...);
int					set_data(t_args *args);
int					set_mt(t_args *args);

// ==================== Constructor Functions ====================
void				*constructor(void *(*c_function)(t_args *args), const char *str, ...);
void            	*c_data(t_args *args);
void            	*c_mt(t_args *args);

// ==================== utils ====================

void set_mem(void **ptr, void *ptr2);

#endif // MT_H