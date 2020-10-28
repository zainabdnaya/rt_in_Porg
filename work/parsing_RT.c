/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_RT.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:48:53 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/28 10:33:13 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void configuration(t_minirt *rt)
{
  
    if (ft_samestr(rt->pars.splitrest[0], "R"))
        resolution_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "A"))
        ambient_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "C"))
        camera_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "L"))
        light_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "sp"))
        sphere_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"pl"))
        plan_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"tr"))
            triangle_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"sq"))
            square_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"cy"))
            cylindre_parsing(rt);
    else
    error(5);
}

void parsing_RT(char *file, t_minirt *rt)
{
    int fd;
    int i = 0;
    if ((fd = open(file, O_RDONLY)) < 0)
        error(3);
    while (get_next_line(fd, &rt->line) > 0)
    {
        rt->pars.splitrest = ft_charSplit(rt->line, " \t\v\n\r\f  ");
        if (rt->pars.splitrest[0])
        {

            configuration(rt);
            
        }

        rt->pars.splitrest = ft_free_split(rt->pars.splitrest);

        ft_stringdel(&rt->line);

    }
    close(fd);
    // if (!rt->pars.parsed)
    //     error(11);
}