/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:46:17 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/05 18:00:47 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_print_info(int key, t_info info)
{
	printf("%s\n", "======================================");
	printf("%s\n", "            Render Done");
	printf("%s\n", "======================================");
	printf("	%s	%d\n", "input:", key);
	printf("	%s	%f\n", "x-pos of cam:", info.xcam);
	printf("	%s	%f\n", "y-pos of cam:", info.ycam);
	printf("	%s	%f\n", "zoom ratio:", info.zoom);
	printf("	%s	%f\n", "real:", info.real);
	printf("	%s	%f\n", "inmaginary:", info.imaginary);
	printf("	%s	%f\n", "iter:", info.max_ite);
	printf("	%s	%d\n", "color:", info.color);
	printf("%s\n\n\n", "======================================");
}

void	ft_print_fract(void)
{
	ft_printf("\n%s\n", "		     FRACTOL			");
	ft_printf("\n%s\n", "		INCORECT ARGUMENT!		");
	ft_printf("\n%s\n", "   you have to choose one of these fractals:");
	ft_printf("\n%s\n", "		- Mandelb");
	ft_printf("\n%s\n", "		- Julia");
	ft_printf("\n%s\n", "		- Newton");
	ft_printf("\n%s\n", "   (to choose a fractal you must put it in a parameter");
	ft_printf("%s\n\n", "   such as : \"./fractol Mandelb\".)");
}

void	ft_print_control(void)
{
	ft_printf("\n%s\n", "		CONTROLS		");
	ft_printf("\n%s\n", "   Arrow or WASD:		Move camera");
	ft_printf("%s\n", "   Scroll up or Left click:	Zoom");
	ft_printf("%s\n", "   Scroll down or right click:	Dezoom");
	ft_printf("%s\n", "   Number Tab:			Load Preset");
	ft_printf("%s\n", "   I and U:			Change iterations");
	ft_printf("%s\n", "   K and J:			Change real Nb");
	ft_printf("%s\n", "   N and M:			Change imaginary Nb");
	ft_printf("%s\n", "   TAB:				Change Colors");
}

int	ft_check_choice(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_print_fract();
		return (0);
	}
	if (!ft_strncmp("Mandelb", argv[1], 8))
	{
		ft_print_control();
		return (1);
	}
	else if (!ft_strncmp("Julia", argv[1], 6))
	{
		ft_print_control();
		return (2);
	}
	else if (!ft_strncmp("Newton", argv[1], 7))
	{
		ft_print_control();
		return (3);
	}
	ft_print_fract();
	return (0);
}
