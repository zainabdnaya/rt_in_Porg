/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:21:25 by zdnaya            #+#    #+#             */
/*   Updated: 2020/05/01 02:21:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	*ft_calloc(size_t count, size_t size)
{
	int				i;
	char			*ptr;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = (size * count) - 1;
	while (i >= 0)
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}
