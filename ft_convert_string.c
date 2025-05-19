/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:04:28 by crosorio          #+#    #+#             */
/*   Updated: 2025/05/19 16:04:32 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_percentage(void)
{
	char	*value;

	value = ft_strdup("%");
	if (!value)
		return (0);
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_handle_string(char *string)
{
	int	count;

	if (!string)
		return (ft_putstr_fd("(null)", 1));
	count = 0;
	count += ft_putstr_fd(string, 1);
	return (count);
}

// validate the case to allow \n and more like that (line 27)
int	ft_handle_character(char c)
{
	if (!ft_isprint(c))
		return (0);
	ft_putchar_fd(c, 1);
	return (1);
}
