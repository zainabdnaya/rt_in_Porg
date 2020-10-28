/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:22:19 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/28 13:31:56 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double convert_to_double(char *string)
{
    int sign;
    double decimal;
    int moy;

    moy = 0;
    sign = 1;
    decimal = 0.0;
    if (string[0] == '-' && *string++ )
        sign = -1;
    while (ft_isdigit(*string) == 1)
        moy = moy * 10 + (*(string)++ - '0');
    while (*string == '.')
        (string)++;
    while (ft_isdigit(*string) == 1)
        decimal = decimal * 10 + (*(string)++ - '0');
    while (decimal >= 1)
        decimal /= 10;
    decimal += moy;
    return (decimal * sign);
}