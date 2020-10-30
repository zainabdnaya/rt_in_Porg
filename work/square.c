/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:06:20 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/30 13:24:09 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void square_parsing(t_minirt *rt)
{
    int count;
    t_square   *square;

    if (!(square = malloc(sizeof(t_square))))
        obj_error(23);
    count = ft_count(rt->pars.splitrest);
    if (count != 5)
    {
        free(square);
        obj_error(27);
    }
    square->center = vectorSplit(rt->pars.splitrest[1]);
    square->normal = vectorSplit(rt->pars.splitrest[2]);
    if ((square->normal.x > 1 || square->normal.x < -1) || (square->normal.y > 1 || square->normal.y < -1) || (square->normal.z > 1 || square->normal.z < -1))
        obj_error(24);
    square->side_size = convert_to_double(rt->pars.splitrest[3]);
    square->color = colorSplit(rt, rt->pars.splitrest[4]);
    // rt->it_square = 4;
    add_objects(&rt->list_obj, copy_square(square->center, square->normal, square->side_size, square->color));
    //write(1," where  Fuck I am?\n",23);
}

double  square_equation(t_minirt *rt,t_objects *list_obj)
{
    t_use scal;
    
    //write(1," where I am?\n",12);
    scal.one = vectorDot(rt->ray_direction,list_obj->normal);
    if(scal.one != 0)
    {
        scal.up = vectorSub(rt->cam->look_from,list_obj->sq_center);
        rt->solution = (-1/scal.one)*vectorDot(scal.up,list_obj->normal);
    }
    if(rt->solution > 0)
    {
        scal.produit = vectorScale(rt->ray_direction, rt->solution);
        scal.point_pos = vectorAdd(rt->cam->look_from,scal.produit);
        scal.q_ed =  vectorSub(scal.point_pos,list_obj->sq_center);
        scal.edge = list_obj->side_size/ 2;

        if (fabs(scal.q_ed.x) > scal.edge || fabs(scal.q_ed.y) > scal.edge || fabs(scal.q_ed.z) > scal.edge)
            return (0);
        return (rt->solution);
    }
    return(0);
}

void calcul_square(t_minirt *rt,t_objects *list_obj,double solution )
{
    t_use scal;

    scal.one_scal = vectorScale(rt->ray_direction, solution);
    list_obj->position = vectorAdd(rt->cam->look_from, scal.one_scal);
    list_obj->normal = vectorNorme(list_obj->normal);
    //rt->l_norm = vectorSub(rt->light->position, rt->list_obj->position);
}