#include "ft_prtinf.h"

int	ft_scan(char specifier, t_list **list, va_list args)
{
		int result;

	if (ft_is_valid_specifier(specifier))
	{
		result = 0;
		if (specifier == 'd' || specifier == 'i')
			result = ft_handle_int(list, va_arg(args, int));
		else if (specifier == 'u')
			result = ft_handle_unsigned_int(list, va_arg(args, unsigned int));
		else if (specifier == 's')
			result = ft_handle_string(list, va_arg(args, char *));
		else if (specifier == 'c')
			result = ft_handle_character(list, va_arg(args, int));
		else if (specifier == 'x' || specifier == 'X')
			result = ft_handle_hexadecimal(list, va_arg(args, unsigned int), specifier);
		else if (specifier == 'p')
			result = ft_handle_pointer(list, va_arg(args, void *));
		else if (specifier == '%')
			result = ft_handle_percentage(list);
		return (result);
	}
	return(0);
}
int ft_process_string(char *ptr, va_list	args, t_list **list)
{
	int i;

	i = 0;
	while (*ptr)
	{
		if (*ptr == '%' && *ptr)
		{
			ptr++;
			ft_add_to_list(ft_substr(ptr+1, i, sizeof(ptr) - i), list);
			if(!ft_scan(*ptr, list, args))
				return(0);
			i = 0;
			ptr++;
		}
		else
		{
			ptr++;
			i++;
		}
	}
	ft_add_to_list(ft_substr(ptr+1, i, sizeof(ptr) - i), list);
	return(1);
}
int	ft_printf(const char *string, ...)
{
	va_list	args;

	if (!string || *string == '\0')
		return (0);
	t_list *list; // lista para almacenar las palabras
	list = NULL;
	va_start(args, string);
	if(!ft_process_string((char*)string,args,&list))
		ft_handle_error(&list);
	va_end(args);
	return (ft_print_list(list));
}
