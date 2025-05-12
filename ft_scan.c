#include "ft_prtinf.h"

char	*ft_read_format_specifier(char *ptr, t_format *format)
{
	// obtenemos primero las flags
	ptr = ft_get_flags(ptr, &format);
	// obtenemos el width
	ptr = ft_get_width(ptr, &format);
	if (*ptr == '.') // obtenemos la precision, si la hay
		ptr = ft_get_precision(ptr, &format);
	// obtenemos el especifie
	if (ft_is_valid_specifier(*ptr))
		format->specifier = *ptr++;
	else
		return (NULL); // specifier inválido
}
int	ft_percentage_specifier_case(t_list **list)
{
	t_list	*node;
	char	*s;

	s = ft_strdup("%");
	if (!s)
		return (0);
	node = ft_lstnew(s);
	if (!node)
	{
		free(s);
		return (0);
	}
	ft_lstadd_back(list, node);
	rerturn(1);
}
int	ft_convert_arg(t_list **list, t_format *format, va_list args)
{
	int	result;

	/*
	 TODO:
	     -terminar las funciones de abajo
	*/
	if (format->specifier == 'd' || format->specifier == 'i')
		result = ft_handle_di(format->specifier, &format, va_arg(args, int));
	else if (format->specifier == 'u')
		result = ft_handle_uint(format, va_arg(args, unsigned int));
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
// funcion donde se hara el escaneo del specifier
char	*ft_scan(char *ptr, t_list **list, va_list args)
{
	t_format	format;

	ft_memset(&format, 0, sizeof(format));
	ptr++; // para saltar el % donde inicia el especifier
	ptr = ft_read_format_specifier(ptr, &format);
	if (!ptr)
		return (NULL); // liberar struct?
	if (format.specifier == '%')
		if (!ft_percentage_specifier_case(list))
			return (NULL);
	if(!ft_convert_arg(list,&format,args))
	  return(NULL);
	return (ptr);
	// guardar la variable procesada de acuerdo a su formato
}
/**
		TODO:
			- create a new function to handle this if format.specifier == '%'
				and call the function (it is no created yet) to convert the arg and
				store it in the list
		*/
