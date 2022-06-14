/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:29:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/14 15:13:17 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_exit(char *message, t_param *world)
{
	/*	Outputs an error message, free what needs to be freed
		and exits the program.	*/

	// fonction pour bien clean
	(void)world;
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	free(world);
	exit(EXIT_FAILURE);
}
