/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:43:14 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/27 11:27:55 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void print_list_sphere(t_objects *ip)
{

    while (ip != NULL)
    {
        printf("Radiuds ===>%f\n", ip->radius);
        printf("Center==> %f\n", ip->center.x);
        printf("Center==> %f\n", ip->center.y);
        printf("Center==> %f\n", ip->center.z);
        printf("Color==> %f\n",  ip->color.r);
        printf("Color==> %f\n",  ip->color.g);
        printf("Color==> %f\n",  ip->color.b);
        //printf("solution ===>%f\n",ip->solution);

        // printf("====>%d\n", ip->a);
        // printf("====>%d\n", ip->b);
        // printf("====>%d\n", ip->c);
        ip = ip->next;
    }
    printf("\n");
}

void print_list_pal(t_objects *ip)
{

    while (ip != NULL)
    {
        printf("point==> %f\n", ip->point.x);
        printf("point==> %f\n", ip->point.y);
        printf("point==> %f\n", ip->point.z);
        printf("p_norm==> %f\n", ip->p_norm.x);
        printf("p_norm==> %f\n", ip->p_norm.y);
        printf("p_norm==> %f\n", ip->p_norm.z);
        printf("Color==> %f\n",  ip->color.r);
        printf("Color==> %f\n",  ip->color.g);
        printf("Color==> %f\n",  ip->color.b);
        //printf("solution ===>%f\n",ip->solution);

        // printf("====>%d\n", ip->a);
        // printf("====>%d\n", ip->b);
        // printf("====>%d\n", ip->c);
        ip = ip->next;
    }
    printf("\n");
}


void print_list_tr(t_objects *ip)
{

    while (ip != NULL)
    {
        printf("point_a==> %f\n", ip->point_a.x);
        printf("point_a==> %f\n", ip->point_a.y);
        printf("point_a==> %f\n", ip->point_a.z);
        printf("point_b==> %f\n", ip->point_b.x);
        printf("point_b==> %f\n", ip->point_b.y);
        printf("point_b==> %f\n", ip->point_b.z);
        printf("point_c==> %f\n", ip->point_c.x);
        printf("point_c==> %f\n", ip->point_c.y);
        printf("point_c==> %f\n", ip->point_c.z);
        printf("Color==> %f\n",  ip->color.r);
        printf("Color==> %f\n",  ip->color.g);
        printf("Color==> %f\n",  ip->color.b);
        //printf("solution ===>%f\n",ip->solution);

        // printf("====>%d\n", ip->a);
        // printf("====>%d\n", ip->b);
        // printf("====>%d\n", ip->c);
        ip = ip->next;
    }
    printf("\n");
}


void    print_list(t_objects *ip)
{
    while(ip != NULL)
    {
        printf("triangle->point_a==> %f\n", ip->point_a.x);
        printf("triangle->point_a==> %f\n", ip->point_a.y);
        printf("triangle->point_a==> %f\n", ip->point_a.z);
    
        printf("plan->p_norm==> %f\n", ip->p_norm.x);
        printf("plan->p_norm==> %f\n", ip->p_norm.y);
        printf("plan->p_norm==> %f\n", ip->p_norm.z);
        
        printf("sphetre->Radiuds ===>%f\n", ip->radius);

        printf("square->Radiuds ===>%f\n", ip->side_size);

            ip = ip->next;
    }
    printf("\n");
}