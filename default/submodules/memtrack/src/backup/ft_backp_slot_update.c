/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backp_slot_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:02:20 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 21:29:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static t_list	*ft_collect_all_nodes(t_slot **slots, size_t count)
{
	t_list	*all_nodes;
	t_slot	*curr;
	t_slot	*top;
	size_t	i;

	all_nodes = NULL;
	i = 0;
	while (i < count)
	{
		curr = slots[i];
		while (curr)
		{
			top = curr->top;
			curr->top = NULL;
			ft_lstadd_back(&all_nodes, ft_lstnew(curr));
			curr = top;
		}
		i++;
	}
	return (all_nodes);
}

static void	ft_rehash_all_nodes(t_backup *backup, t_list *all_nodes)
{
	t_list	*node;
	t_slot	*item;
	size_t	index;

	node = all_nodes;
	while (node)
	{
		item = (t_slot *)node->content;
		index = ft_hash_str(item->group_id) % backup->slot_count;
		item->top = backup->slots[index];
		backup->slots[index] = item;
		node = node->next;
	}
}

void	ft_backup_slot_update(t_backup **backup, size_t new_slot_count)
{
	t_list	*all_nodes;
	t_slot	**old_slots;
	size_t	old_count;

	if (!backup || !*backup || new_slot_count == 0)
		return ;
	old_slots = (*backup)->slots;
	old_count = (*backup)->slot_count;
	all_nodes = ft_collect_all_nodes(old_slots, old_count);
	free(old_slots);
	(*backup)->slots = ft_slot_array_new(new_slot_count);
	if (!(*backup)->slots)
	{
		ft_lstclear(&all_nodes, NULL);
		return ;
	}
	(*backup)->slot_count = new_slot_count;
	ft_rehash_all_nodes(*backup, all_nodes);
	ft_lstclear(&all_nodes, NULL);
}
