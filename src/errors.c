/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:29:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/13 13:03:07 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_exit(char *message, t_param *world)
{
	/*	Outputs an error message, free what needs to be freed
		and exits the program.	*/

	(void)world;
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	free(world);
	exit(EXIT_FAILURE);
}
