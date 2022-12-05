/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:50:20 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/05 00:57:58 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifdef __linux__
#  define KB_ESC		65307
#  define KB_X			120
#  define KB_Z			122
#  define KB_UP			65362
#  define KB_DOWN		65364
#  define KB_LEFT		65361
#  define KB_RIGHT		65363
#  define KP_ADD		65451
#  define KP_SUBTRACT	65453
#  define KB_I			105
#  define KB_U			117
#  define KB_R			114
#  define KP_4			65430
#  define KP_2			65433
#  define KP_1			65434
#  define KB_F			102
# elif __APPLE__
#  define KB_ESC		53
#  define KB_X			7
#  define KB_Z			6
#  define KB_UP			126
#  define KB_DOWN		125
#  define KB_LEFT		123
#  define KB_RIGHT		124
#  define KP_ADD		69
#  define KP_SUBTRACT	78
#  define KB_I			34
#  define KB_U			32
#  define KB_R			15
#  define KP_4			86
#  define KP_2			84
#  define KP_1			83
#  define KB_F			3
# endif
