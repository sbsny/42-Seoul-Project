/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:28:22 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 17:05:08 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_list(t_data *old)
{
	t_oldmap	*tem;

	tem = NULL;
	while (old->oldmap)
	{
		tem = old->oldmap;
		old->oldmap = old->oldmap->next;
		if (tem->row)
			free(tem->row);
		free(tem);
	}
	old->oldmap = NULL;
}

void	free_2d_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free (str);
}

void	free_2d_array1(int **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free (str);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->tex)
		free(data->tex);
	if (data->worldmap)
		free_2d_array(data->worldmap);
	if (data->texture)
		free_2d_array1(data->texture);
	if (data->oldmap)
		free_list(data);
}
