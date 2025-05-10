#include "ft_prtinf.h"

char	*ft_read_format_specifier(char *ptr, t_format *format)
{
	// obtenemos primero las flags
	ptr = ft_get_flags(ptr, &format);
	if (!ptr)
		return (NULL);
	// obtenemos el width
	ptr = ft_get_width(ptr, &format);
	if (!ptr)
		return (NULL);
	if (*ptr == '.') // obtenemos la precision, si la hay
	{
		ptr = ft_get_precision(ptr, &format);
		if (!ptr)
			return (NULL);
	}
	// obtenemos el especifie
	if (ft_is_valid_specifier(*ptr))
		format->specifier = *ptr++;
	else
		return (NULL); // specifier inválido
}
// funcion donde se hara el escaneo del specifier
char	*ft_scan(char *ptr, t_list **list, va_list args)
{
	t_format	format;
	char		*s;
	t_list		*node;

	ft_memset(&format, 0, sizeof(format));
	ptr++; // para saltar el % donde inicia el especifier
	ptr = ft_read_format_specifier(ptr,&format);
	if(!ptr)
	 return(NULL);
	if (format.specifier == '%')
	{
		s = ft_strdup("%");
		if (!s)
			return (NULL);
		node = ft_lstnew(s);
		if (!node)
		{
			free(s);
			return (NULL);
		}
		ft_lstadd_back(list, node);
		return (ptr);
	}
	/**
	  TODO:
	       - how handle error in the functions of ft_scan_aux
	       - create a new function to handle this if format.specifier == '%'
		     and call the function (it is no created yet) to convert the arg and
			 store it in the list
	 */
	// guardar la variable procesada de acuerdo a su formato
}
