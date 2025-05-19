#include "ft_printf.h"

int	ft_scan(char specifier, va_list args)
{
	int	result;

	if (ft_is_valid_specifier(specifier))
	{
		result = 0;
		if (specifier == 'd' || specifier == 'i')
			result = ft_handle_int(va_arg(args, int));
		else if (specifier == 'u')
			result = ft_handle_unsigned_int(va_arg(args, unsigned int));
		else if (specifier == 's')
			result = ft_handle_string(va_arg(args, char *));
		else if (specifier == 'c')
			result = ft_handle_character(va_arg(args, int));
		else if (specifier == 'x' || specifier == 'X')
			result = ft_handle_hexadecimal(va_arg(args, unsigned int),
					specifier);
		else if (specifier == 'p')
			result = ft_handle_pointer(va_arg(args, void *));
		else if (specifier == '%')
			result = ft_handle_percentage();
		return (result);
	}
	return (0);
}

int	ft_process_string(char *ptr, va_list args)
{
	int	count;

	count = 0;
	while (*ptr)
	{
		if (*ptr == '%' && ptr + 1 != NULL)
		{
			while(!ft_is_valid_specifier(*ptr))
			 ptr++;
//			ptr++;
			count += ft_scan(*ptr, args);
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
