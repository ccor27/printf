#include "ft_prtinf.h"

static char	*apply_precision_u(t_format *format, char *str_value)
{
	int		str_len;
	char	*padded_str;

	str_len = ft_strlen(str_value);
	if (format->precision > str_len)
	{
		padded_str = malloc(format->precision + 1);
		if (!padded_str)
			return (free_and_return_null(str_value));
		padded_str[format->precision] = '\0';
		ft_memset(padded_str, '0', format->precision - str_len);
		ft_memcpy(padded_str + (format->precision - str_len), str_value, str_len
			+ 1);
		free(str_value);
		return (padded_str);
	}
	return (str_value);
}

static char	*apply_width_u(t_format *format, char *str_value)
{
	int		str_len;
	char	*padded_str;
	char	padding_char;

	str_len = ft_strlen(str_value);
	if (format->width > str_len)
	{
		padded_str = malloc(format->width + 1);
		if (!padded_str)
			return (free_and_return_null(str_value));
		padded_str[format->width] = '\0';
		if (format->flag_zero && !format->has_precision)
			padding_char = '0';
		else
			padding_char = ' ';
		if (format->flag_minus)
			ft_memcpy(padded_str, str_value, str_len + 1);
		else
			ft_memcpy(padded_str + (format->width - str_len), str_value, str_len
				+ 1);
		if (format->flag_minus)
			ft_memset(padded_str + str_len, padding_char, format->width
				- str_len);
		else
			ft_memset(padded_str, padding_char, format->width - str_len);
		free(str_value);
		return (padded_str);
	}
	return (str_value);
}

int	ft_handle_unsigned_int(t_format *format, t_list **list,
		unsigned int value)
{
	char	*value_str;

	if (value > 4294967295)
		return (0);
	value_str = ft_utoa(value);
	if (!value_str)
		return (0);
	value_str = apply_precision_u(format, value_str);
	if (!value_str)
		return (0);
	value_str = apply_width_u(format, value_str);
	if (!value_str)
		return (0);
	ft_add_to_list(value_str, list);
	return (1);
	// almacenar en la lista y retornar un 1
}
