/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:05:29 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/26 13:49:29 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void resolution_parsing(t_minirt *rt)
{
    int count;

    if (!(resol_check(rt->pars.splitrest[1])) || !(resol_check(rt->pars.splitrest[2])) )
        error(0.1);
    count = ft_count(rt->pars.splitrest);
    if (count != 3)
        error(8);
    rt->resol.WIDTH = ft_atoi(rt->pars.splitrest[1]);
    rt->resol.HEIGHT = ft_atoi(rt->pars.splitrest[2]);
    if ((rt->resol.WIDTH < 1 && rt->resol.WIDTH >= 0) || ( rt->resol.HEIGHT >= 0 && rt->resol.HEIGHT < 1))
        error(6);
    if (rt->resol.WIDTH <= 0 && rt->resol.HEIGHT<= 0 )
        error(7);
    rt->pars.parsed = 1;
    rt->resol.WIDTH > 2560 ? rt->resol.WIDTH = 2560 : 0;
    rt->resol.HEIGHT > 1395 ? rt->resol.HEIGHT = 1395 : 0;
}

void camera_parsing(t_minirt *rt)
{
    if (!(rt->cam = malloc(sizeof(t_camera))))
        p_error(13);

    if (ft_count(rt->pars.splitrest) != 4)
    {
        free(rt->cam);
        p_error(10);
    }
    rt->cam->look_from = vectorSplit(rt->pars.splitrest[1]);
    rt->cam->look_at = vectorSplit(rt->pars.splitrest[2]);
    rt->cam->fov = ft_atoi(rt->pars.splitrest[3]);
}

void ambient_parsing(t_minirt *rt)
{
    if (ft_count(rt->pars.splitrest) != 3)
        p_error(16);
    rt->ambient.ratio = convert_to_double(rt->pars.splitrest[1]);
    rt->ambient.color = colorSplit(rt, rt->pars.splitrest[2]);
    if (rt->ambient.ratio > 1 || rt->ambient.ratio < 0)
        p_error(17);
}

void light_parsing(t_minirt *rt)
{
    if (!(rt->light = malloc(sizeof(t_light))))
        p_error(13);
    if (ft_count(rt->pars.splitrest) != 4)
    {
        free(rt->light);
        p_error(15);
    }
    rt->light->position = vectorSplit(rt->pars.splitrest[1]);
    rt->light->ratio = convert_to_double(rt->pars.splitrest[2]);
    rt->light->rgb = colorSplit(rt, rt->pars.splitrest[3]);
    if (rt->light->ratio > 1 || rt->light->ratio < 0)
        p_error(20);


}
