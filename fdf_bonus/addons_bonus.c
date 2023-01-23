/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addons_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:15:11 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/22 23:23:25 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#define LINE_SIZE			23
#define MENU_TAB			110
#define SECOND_PAGE			400
#define SECOND_PAGE_VALUES	600

void	second_info(t_fdf *mats, int line)
{
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "//MAP INFO:");
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "Map height = ");
	print_nbr(mats, SECOND_PAGE_VALUES, line, mats->height);
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "Map width  = ");
	print_nbr(mats, SECOND_PAGE_VALUES, line, mats->width);
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "Origin X   = ");
	print_nbr(mats, SECOND_PAGE_VALUES, line, mats->origin->data[X][0]);
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "Origin Y   = ");
	print_nbr(mats, SECOND_PAGE_VALUES, line, mats->origin->data[Y][0]);
}

void	second_wind(t_fdf *mats)
{
	int	line;

	line = LINE_SIZE * 2;
	print_str(mats, SECOND_PAGE, line, "//COLOR SCHEME:");
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "1 = SNOW WHITE");
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "2 = RED GREEN");
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "3 = FLAT EARTH");
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "4 = SCORCHED EARTH");
	line += LINE_SIZE;
	print_str(mats, SECOND_PAGE, line, "5 = BLOOD REALM");
	second_info(mats, line);
}

void	ultimate_spell_writer_tatima(t_fdf *mats, int line)
{
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "DOWN  = +X translation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "LEFT  = -Y translation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "RIGHT = +Y translation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "Z     = ZOOM IN");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "C     = ZOOM OUT");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "TAB   = ISO VIEW");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "X     = X VIEW");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "Y     = Y VIEW");
}

void	ultimate_spell_writer(t_fdf *mats)
{
	int	line;

	line = LINE_SIZE;
	print_str(mats, 200, line, "//The Book Of         Ultimate Spells\\\\");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "//CONTROLS:");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "S     = -X rotation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "W     = +X rotation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "A     = -Y rotation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "D     = +Y rotation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "Q     = -Z rotation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "E     = +Z rotation");
	line += LINE_SIZE;
	print_str(mats, MENU_TAB, line, "UP    = -X translation");
	ultimate_spell_writer_tatima(mats, line);
}

void	epic_spellbook(t_fdf *mats)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mats->mlx, \
	"assets/spellbook.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mats->mlx, mats->win, img, 0, 0);
	ultimate_spell_writer(mats);
	second_wind(mats);
}
