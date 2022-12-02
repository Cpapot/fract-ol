/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:46:17 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/02 16:17:36 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_print_info(int key, t_info info)
{
	printf("%s\n", "======================================");
	printf("%s\n", "            Render Done");
	printf("%s\n", "======================================");
	printf("	%s	%d\n", "input:", key);
	printf("	%s	%f\n", "x-pos of cam:", info.xcam);
	printf("	%s	%f\n", "y-pos of cam:", info.ycam);
	printf("	%s	%f\n", "zoom ratio:", info.zoom);
	printf("%s\n\n\n", "======================================");
}
