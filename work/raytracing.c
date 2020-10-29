/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:45:19 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/29 14:53:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void      calcul_data(t_minirt *rt)
{
        if(rt->check == 1)
                calcul_sphere(rt);
        else if (rt->check== 2) 
                calcul_plan(rt);
        else if (rt->check== 3)
                calcul_triangle(rt);
        else if (rt->check == 4)
            calcul_square(rt);
        else if (rt->check == 5)
        //{
            
        //write(1," where  Fuck I am?\n",23);
            calcul_cylindre(rt);
        //}
        else
            return;
}
void        Witch_object(t_minirt *rt,double *cmp)
{
    t_objects *tmp;
    double var = 0;
    rt->exist = 0;
    tmp = rt->list_obj;
    
    while( rt->list_obj != NULL)
    {
        //print_list(rt->list_obj);
        if(rt->witch_object == 1)
            {
                //write(1, "i am here\n",11);
            var = sphere_equation(rt);
            }
        else if(rt->witch_object == 2)
            var  = plan_equation(rt);
        else if (rt->witch_object == 3)
             var = triangle_equation(rt);
        else if (rt->witch_object == 4)
            var = square_equation(rt);
        else if(rt->witch_object == 5)
        {

            var  = cylindre_equation(rt);
        }
        if (var > 0.0 && var < *cmp)
        {
            rt->hit1 = var;
            *cmp = rt->hit1;
            rt->list_obj->solution = *cmp;
            rt->check = rt->witch_object;
            calcul_data(rt);
            //very important to calcul the coloror it won't happen
            object_coloration(&rt->list_obj->light_norm,&rt->list_obj->normal,&rt->list_obj->position,&rt->list_obj->color);
            rt->exist = 1;
        }

       rt->list_obj  = rt->list_obj->next;
        }
    rt->list_obj = tmp;

 }
 
void  object_coloration(t_vector *l_norm, t_vector *n_norm,t_vector *position,t_color *result_color )
{
    t_minirt *rt;
    
    rt->result_color = rt->list_obj->color;
    //rt->l_norm = rt->list_obj->light_norm;
    rt->n_norm = rt->list_obj->normal;
    rt->position = rt->list_obj->position;
}

t_color ray_Tracing(t_minirt *rt)
{
    int i;
    t_objects  *tmp;
    t_color black = {0, 0, 0};
    t_color test = {255,0,255};
    t_color color_result;
    t_color result1;
    int hit;   
    double     cmp = INT_MAX; 


    Witch_object(rt,&cmp);
    if (rt->exist == 1)
    {

    result1.r = 255  * (ambiant(rt).x + diffuse(rt).x + spec(rt).x);
    result1.g = 255  * (ambiant(rt).y + diffuse(rt).y + spec(rt).y);
    result1.b = 255  * (ambiant(rt).z + diffuse(rt).z + spec(rt).z);
                // write(1," where the Fuck I am?\n",26);
    result1.r = min(255, max(0, result1.r));
    result1.g = min(255, max(0, result1.g));
    result1.b = min(255, max(0, result1.b));
    

    return (result1);
    }
    else
        return(black);
   }

   /********Shadow*****************************
        rt->ray_origin.x = rt->sphere->position.x + 0.001 * rt->phong.n.x;
        rt->ray_origin.y = rt->sphere->position.y + 0.001 * rt->phong.n.y;
        rt->ray_origin.z = rt->sphere->position.z + 0.001 * rt->phong.n.z;
        
        rt->ray_direction.x = rt->light->position.x - rt->sphere->position.x;
        rt->ray_direction.y = rt->light->position.y - rt->sphere->position.y;
        rt->ray_direction.z = rt->light->position.z - rt->sphere->position.z;
        rt->ray_direction = vectorNorme(rt->ray_direction);*/
