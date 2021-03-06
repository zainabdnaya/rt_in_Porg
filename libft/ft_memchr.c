/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:54:39 by zdnaya            #+#    #+#             */
/*   Updated: 2019/11/02 14:08:53 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(void *s, int c, size_t n)
{
	char			*src;

	src = (char *)s;
	while (n-- > 0)
	{
		if (*src != c)
			src++;
		else
			return (src);
	}
	return (NULL);
}
