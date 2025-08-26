/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/06 10:51:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# include "libft.h"
# include "math.h"
# include "mtstructs.h"
# include <stdbool.h>
# include <stdlib.h>

# define PI 3.14159265358979323846

// ==================== Memory Management ====================

void		ft_mtfree(void *mt);
int			ft_mtremove(t_mt **head, t_mt *target, bool free_node);
void		ft_mtdelete(const char *key);
void		ft_mtclear(t_mt **lst);
t_mt		*ft_mtnew(const char *key, const char *id);

// ==================== Count Functions ====================

// ==================== Iteration and Set Functions ====================

// ==================== Movement Functions ====================

// ==================== Deletion Functions ====================

// ==================== Insertion Functions ====================

// ==================== Add Functions ====================

int			ft_mtadd_back(t_mt **node, t_mt *new_node);

// ==================== Backup Functions =======================

size_t		ft_hash(t_mt *key);
size_t		ft_hash_str(const char *str);

//
t_backup	*ft_backup_new(size_t slot_count);
t_backup	*ft_backup_static(size_t slot_count, bool new, bool clear);

void		ft_backup_add(t_backup **backup, t_mt *node);
void		ft_backup_add_track(t_backup **backup, t_track *track);
void		ft_backup_add_slot(t_backup **backup, t_slot *slot);

int			ft_backup_clear(t_backup **backup);
void		ft_backup_remove(t_backup **backup, t_mt *target, bool free_target);
void		ft_backup_delete(t_backup **backup, const char *key);

t_mt		*ft_backup_search(t_backup **backup, const char *key);

// ==================== Backup Slot Functions ====================

int			ft_backup_remove_slot(t_backup **backup, t_mt *target,
				bool free_slot);
void		ft_backup_slot_update(t_backup **backup, size_t new_slot_count);
void		ft_backup_add_slot_mt(t_backup **backup, t_mt *node);

// ==================== Slot Functions ====================

void		ft_slot_clear(t_slot **slots, size_t slot_count, bool free_data);
t_slot		*ft_slot_search(t_slot *slot, const char *key);
t_slot		*ft_slot_find(t_slot **slots, size_t slot_count, t_slot *target);
int			ft_slot_remove(t_slot **slots, size_t slot_count, t_mt *target,
				bool free_target);
t_slot		**ft_slot_array_new(size_t slot_count);
void		ft_slot_add_botton(t_slot **slots, t_slot *new_slot);
t_slot		*ft_slot_new(const char *id, const char *group_id, t_mt *node);
void		ft_slot_free(t_slot **slot, bool free_node);
int			ft_slot_add_mt(t_slot ***slot, size_t slot_count, t_mt *node);
void		ft_slot_hash_add(t_slot **slots, size_t slot_count, t_slot *node);
t_mt		*ft_slot_search_mt(t_slot **slots, size_t slot_count,
				const char *id);
t_slot		*ft_slot_hash_search(t_slot **slots, size_t slot_count,
				const char *key);

// ==================== Track Functions ====================

t_track		*ft_track_find(t_track *tracks, t_track *target);
t_track		*ft_track_new(const char *group_id, const char *node_id,
				t_mt *node);
void		ft_track_clear(t_track **tracks, bool free_data);
void		ft_track_free(t_track **track, bool free_node);
int			ft_track_add_back(t_track **node, t_track *new_node);
t_track		*ft_track_search(t_track *track, const char *key);
int			ft_track_remove(t_track **tracker, t_track *node, bool free_node);

// ==================== Group Functions ====================

t_group		*ft_group_new(const char *id);
t_group		*ft_group_search(t_group *groups, const char *id);
void		ft_group_add_back(t_group **group, t_group *new_group);
void		ft_group_add_track(t_group **group, t_track *track);
void		ft_group_clear(t_group **group, bool free_data);
void		ft_group_free(t_group **group, bool free_data);
int			ft_group_add_mt(t_group **group, t_mt *node);
t_mt		*ft_group_search_mt(t_group *group, const char *key);

// ==================== Filter Functions ====================

// ==================== Fold Functions ====================

// ==================== Collection Functions ====================

// ==================== Compare Functions ====================

int			ft_mtkeycmp(const t_mt *mt1, const char *key);

// ==================== Search Functions ====================

t_mt		*ft_mtsearch(t_mt *head, const char *key);
t_mt		*ft_mtfind(t_mt *head, t_mt *mt);
t_mt		*ft_mtget(const char *key);

// ==================== Navigation Functions ====================
t_mt		*ft_mtlast(t_mt **node, bool move);

// ==================== Manipulation Functions ====================

// ===================== Getter Functions ====================

char		*ft_mtget_key(t_mt *mt);
void		*ft_mtget_id(t_mt *mt);
void		*ft_mtget_data(t_mt *mt);
void		*ft_mtget_data_free(t_mt *mt);
void		*ft_mtget_addon(t_mt *mt);
void		*ft_mtget_addon_free(t_mt *mt);

// ==================== Setter Functions ====================

int			ft_mtset(const char *key, void *data,
				void (*set_func)(struct s_mt *, void *));

void		ft_mtset_key(t_mt *mt, void *key);
void		ft_mtset_id(t_mt *mt, void *id);
void		ft_mtset_data(t_mt *mt, void *data);
void		ft_mtset_data_free(t_mt *mt, void *data_free);

void		ft_mtset_addon(t_mt *mt, void *addon);
void		ft_mtset_addon_free(t_mt *mt, void *addon_free);

// ==================== utils ====================

void		set_mem(void **ptr, void *ptr2);

#endif // MT_H