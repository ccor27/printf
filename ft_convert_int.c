/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:04:19 by crosorio          #+#    #+#             */
/*   Updated: 2025/05/19 16:04:20 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_int(int num)
{
	char	*value;
	int		count;

	count = 0;
	value = ft_itoa(num);
	if (!value)
		return (0);
	count += ft_putstr_fd(value, 1);
	return (count);
}

int	ft_handle_unsigned_int(unsigned int num)
{
	char	*value;
	int		count;

	count = 0;
	value = ft_utoa(num);
	if (!value)
		return (0);
	count += ft_putstr_fd(value, 1);
	return (count);
}

static void	to_lower(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		ptr[i] = ft_tolower(ptr[i]);
		i++;
	}
}

int	ft_handle_hexadecimal(unsigned int num, char c)
{
	char	*value;
	int		count;

	count = 0;
	value = ft_itoa_base(num, 16);
	if (!value)
		return (0);
	if (c == 'x')
		to_lower(value);
	count += ft_putstr_fd(value, 1);
	return (count);
}

int	ft_handle_pointer(void *ptr)
{
	char	*hexa_value;
	char	*result;
	int		count;

	count = 0;
	if (!ptr)
		count += ft_putstr_fd("(nil)", 1);
	else
	{
		hexa_value = ft_itoa_base((unsigned long)ptr, 16);
		if (!hexa_value)
			return (0);
		result = ft_strjoin("0x", hexa_value);
		free(hexa_value);
		if (!result)
			return (0);
		to_lower(result);
		count += ft_putstr_fd(result, 1);
	}
	return (count);
}
