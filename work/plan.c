/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:59:41 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/26 10:06:16 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void plan_parsing(t_minirt *rt)
{
    int count;
    t_plan *plan;
    t_objects *tmp;
    tmp = malloc(sizeof(t_objects));

    if (!(plan = malloc(sizeof(t_plan))))
        obj_error(23);
    count = ft_count(rt->pars.splitrest);
    if (count != 4)
    {
        free(plan);
        obj_error(25);
    }
    plan->point = vectorSplit(rt->pars.splitrest[1]);
    plan->norm = vectorSplit(rt->pars.splitrest[2]);
    if((plan->norm.x > 1 ||  plan->norm.x < -1) || (plan->norm.y > 1 || plan->norm.y < -1) || (plan->norm.z > 1 || plan->norm.z < -1))
           obj_error(24);     
    plan->color = colorSplit(rt, rt->pars.splitrest[3]);
    rt->witch_object = 2;
    tmp = copy_plan(plan->point,plan->norm,plan->color);
    add_objects(&rt->list_obj,tmp);
    //write(1," where  Fuck I am?\n",23);

}


double      plan_equation(t_minirt *rt)
{
    t_use scal;
    
    scal.denominator = vectorDot(rt->list_obj->p_norm,rt->ray_direction);
     if ( scal.denominator != 0.0)
    {
        scal.one_scal = vectorSub(rt->cam->look_from,rt->list_obj->point);
        rt->solution = (-1) * (vectorDot(scal.one_scal,rt->list_obj->p_norm)) / scal.denominator;
        if ( rt->solution > 0)
            return (rt->solution);
        rt->list_obj->normal =rt->list_obj->p_norm;
        if(scal.denominator < 0)
            rt->list_obj->normal = vectorScale(rt->list_obj->p_norm,(-1));
    }
    return (0);
}


void    calcul_plan(t_minirt *rt)
{
  
    
    rt->list_obj->position.x = rt->cam->look_from.x + rt->list_obj->solution * rt->ray_direction.x;
    rt->list_obj->position.y = rt->cam->look_from.y + rt->list_obj->solution * rt->ray_direction.y;
    rt->list_obj->position.z = rt->cam->look_from.z + rt->list_obj->solution * rt->ray_direction.z;

}