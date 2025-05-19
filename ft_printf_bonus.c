#include "ft_printf_bonus.h"

int ft_handle_cases(t_format *format, va_list args)
{
	int result;

	result = 0;
	if (format->specifier == 'd' || format->specifier == 'i')
		result = ft_handle_di(format, va_arg(args, int));//hecho
	else if (format->specifier == 'u')
		result = ft_handle_unsigned_int(format, va_arg(args, unsigned int));//hecho
	else if (format->specifier == 's')
		result = ft_handle_str(format, va_arg(args, char *));
	else if (format->specifier == 'c')
		result = ft_handle_char(format, va_arg(args, int));
	else if (format->specifier == 'x' || format->specifier == 'X')
		result = ft_handle_hex(format, va_arg(args, unsigned int));
	else if (format->specifier == 'p')
		result = ft_handle_pointer(format, va_arg(args, void *));
	return(result);
}

int	ft_scan_specifier(char **ptr, t_format *format)
{
	ft_get_flags(ptr, format);
	ft_get_width(ptr, format);
	if (**ptr == '.')
		ft_get_precision(ptr, format);
	if (ft_is_valid_specifier(**ptr))
		format->specifier = **ptr;
	else
		return (0); // specifier inválido
	return (1);
}

int	ft_scan(char **ptr, va_list args)
{
	t_format	*format;
	int			count;

	format = (t_format*)malloc(sizeof(t_format));
	if(!format)
		return(0);
	count = 0;
	ft_memset(&format, 0, sizeof(*format));
	if (!ft_scan_specifier(ptr, format))
		return (count);
	else
	{
		if (format->specifier == '%')
			return(ft_handle_percentage());
		return(ft_handle_cases(format, args));
	}
}
int	ft_process_string(char *ptr, va_list args)
{
	int	count;

	count = 0;
	while (*ptr)
	{
		if (*ptr == '%' && ptr + 1 != NULL)
		{
			ptr++;
			count += ft_scan(&ptr, args);
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			count++;
		}
		ptr++;
	}
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;

	if (!string)
		return (-1);
	count = 0;
	va_start(args, string);
	count += ft_process_string((char *)string, args);
	va_end(args);
	return (count);
}
