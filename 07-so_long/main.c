/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:48:20 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:48:20 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (name_check(argv[1]) == FAILURE)
			error_msg(ERRBER, &data);
		create_map(argv[1], &data);
		init_map(&data);
		check_map(&data);
		f_init_player(&data);
		init_window(&data);
		init_images(&data);
		loop_images(data);
		destroy_images(&data);
		ft_free(&data);
	}
	else
		error_msg2(ARGERR);
}
