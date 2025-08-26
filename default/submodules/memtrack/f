t_mt  *ft_build_line(t_mt **start, t_cords origin, t_offset offset, t_backup **backup)
{
    t_offset step;
	t_cords pos;
	t_mt *current;
	int count;
	int idx;
	char *key;
	
	step = ft_offset_new(direction, elevation, 1.0f);
    pos = origin;
    current = *start;
    count = (int)(distance);
	idx = 0;
    while (count > 0)
    {
		key = ft_itoa(idx);
        t_mt *node = ft_mtnew2(key, NULL, backup);
		free(key);
        if (!node)
           break;
        pos = ft_calc_cords_3d(pos, step);
        node->cords = pos;
        ft_mtadd_link(&current, node, step, NULL);
        current = node;
        count--;
		idx++;
    }
	return (current);
}


bool filter(t_mt *node, t_data data)
{
	if (data.item)
	{
		if (ft_strncmp(data.label, "cmp", 3) == 0)
		{
			if (ft_strncmp(node->key, data.item, data.size) == 0)
				return (true);
		}
	}
	return (false);
}