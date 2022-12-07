/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:50:20 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/07 01:11:57 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define KB_ESC		65307
#  define KB_W			122
#  define KB_A			113
#  define KB_S			115
#  define KB_D			100
#  define KB_UP			65362
#  define KB_DOWN		65364
#  define KB_LEFT		65361
#  define KB_RIGHT		65363
#  define KB_N			110
#  define KB_M			44
#  define KB_J			106
#  define KB_K			107
#  define KB_I			105
#  define KB_U			117
#  define KP_4			65430
#  define KP_3			65435
#  define KP_2			65433
#  define KP_1			65436
#  define KB_TAB		65289
#  define KP_PLUS		65451
#  define KP_MINUS		65453
# elif __APPLE__
#  include "../mlx/mlx.h"
#  define KB_ESC		53
#  define KB_W			13
#  define KB_A			0
#  define KB_S			1
#  define KB_D			2
#  define KB_UP			126
#  define KB_DOWN		125
#  define KB_LEFT		123
#  define KB_RIGHT		124
#  define KB_N			45
#  define KB_M			46
#  define KB_J			38
#  define KB_K			40
#  define KB_I			34
#  define KB_U			32
#  define KP_4			86
#  define KP_3			85
#  define KP_2			84
#  define KP_1			83
#  define KB_TAB		48
#  define KP_PLUS		69
#  define KP_MINUS		78
# endif
