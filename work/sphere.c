/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 00:17:23 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/28 12:34:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void        sphere_parsing(t_minirt *rt)
{
    int count;
    t_sphere    *sphere;

    if(!(sphere =  malloc(sizeof(t_sphere))))
        obj_error(23);
    count = ft_count(rt->pars.splitrest);
    if ( count != 4)
    {
            free(sphere);
            obj_error(21);
    }
    sphere->center = vectorSplit(rt->pars.splitrest[1]);
    sphere->radius = convert_to_double(rt->pars.splitrest[2]);
    if ( sphere->radius < 0 )
        obj_error(22);
    sphere->color  = colorSplit(rt,rt->pars.splitrest[3]); 
    rt->witch_object = 1;
       printf("Sphere_Center==> %f\n",sphere->center.x);
    printf("Sphere_Center==> %f\n",sphere->center.y);
    printf("Sphere_Center==> %f\n",sphere->center.z);
    add_objects(&rt->list_obj, copy_spher(sphere->center, sphere->radius, sphere->color));
 
    //print_list(rt->list_obj);
    
}

double sphere_equation(t_minirt *rt)
{
    //print_list(rt->list_obj);
    t_use scal;
    
    scal.scal1 = vectorDot(rt->ray_direction, rt->ray_direction); // A
    scal.dist = vectorSub(rt->cam->look_from, rt->list_obj->center);
    scal.scal2 = 2 * vectorDot(rt->ray_direction, scal.dist); // B
    scal.rst = vectorDot(scal.dist, scal.dist) - (pow(rt->list_obj->radius, 2)); // C 
    scal.delta = (pow(scal.scal2, 2)) - (4 * scal.scal1 * scal.rst);
    //printf("===>solution: %f\n",scal.delta);                            
    if (scal.delta < 0)
        return (0);
    
    else
    {
        scal.t1 = (-scal.scal2 + sqrt(scal.delta)) / 2 * scal.scal1;
        scal.t2 = (-scal.scal2 - sqrt(scal.delta)) / 2 * scal.scal1;
        if (scal.t1 < 0)
            return (0);
        //write(1," where I am?\n",14);
        if (scal.t1 < scal.t2)
            rt->solution = scal.t1;
        else
            rt->solution = scal.t2;
        //calcul_sphere_data(rt,rt->list_obj->solution);
        return (rt->solution);
    }
}



void      calcul_sphere(t_minirt *rt)
{
    t_use scal;

        scal.one_scal = vectorScale(rt->ray_direction, rt->list_obj->solution);
        rt->list_obj->position = vectorAdd(rt->cam->look_from, scal.one_scal);
        t_vector discrt = vectorSub(rt->list_obj->position, rt->list_obj->center);
        rt->list_obj->normal = vectorNorme((discrt));
    
}