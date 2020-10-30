/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:32:36 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/30 13:25:45 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


t_objects *copy_spher(t_vector center, double radius, t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->center = center;
    obj->radius = radius;
    obj->color  = color;
    obj->witch_objects = 1;

    obj->next = NULL;
    return (obj);
} 

t_objects *copy_plan(t_vector point,t_vector norm, t_color color)
{
    t_objects *obj;
    
    obj = malloc(sizeof(t_objects));

    obj->point = point;
    obj->p_norm = norm;
    obj->color  = color;
    obj->witch_objects = 2;

    obj->next = NULL;
    return (obj);
    
     
}

t_objects *copy_triangle(t_vector point_a, t_vector point_b, t_vector point_c, t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->point_a = point_a;
    obj->point_b = point_b;
    obj->point_c = point_c;
    obj->color = color;
    obj->witch_objects = 3;

    obj->next = NULL;
    return (obj);
}

t_objects *copy_square(t_vector center, t_vector normal,double side_size, t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->sq_center = center;
    obj->normal = normal;
    obj->side_size = side_size;
    obj->color = color;
    obj->witch_objects = 4;

    obj->next = NULL;
    return (obj);
}

t_objects *copy_cylindre(t_vector center, t_vector normal,double diameter,double height,t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->cy_center = center;
    obj->cy_normal = normal;
    obj->diameter = diameter;
    obj->height = height;
    obj->color = color;
    obj->witch_objects = 5;

    obj->next = NULL;
    return (obj);
}

void add_objects(t_objects  **head, t_objects  *new_obj)
{
    t_objects *new;


    if (!head || !new_obj)
        return;
    new = *head;
    if (new)
    {
        while (new->next)
            new = new->next;
        new->next = new_obj;
        new_obj->next = NULL;
    }
    else
       {           

          new_obj->next = NULL;
            *head = new_obj; 
       } 
    
}

// t_objects   *add_one_element(t_objects *obj ,double  solution)
// {
//         obj->solution = solution;

//         return(obj);
// }

// t_objects *put_to_list(t_vector center, double radius, t_color color)
// {
//     t_objects *obj;

//     obj = malloc(sizeof(t_objects));

//     obj->center = center;
//     obj->radius = radius;
//     obj->color  = color;

//     obj->next = NULL;
//     return (obj);
// }