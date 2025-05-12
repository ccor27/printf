#include "ft_prtinf.h"

int	ft_handle_di(char specifier, t_format *format, int value)
{
	char	*value_str;

	// validar min y max de int
	if (value < -2147483648 || value > 2147483647)
		return (NULL);
	if (specifier == 'd')
	{
		// convertir valor dependiendo de las especificaciones
		/*
		  TODO:
		      -terminar las funciones que hay abajo
			  -dividir en int y dec
			  -hacer una prueba hasta el momento con int y dec
		 */
		value_str = ft_itoa(value);
		if (!value_str)
			return (0);
		value_str = apply_precision_di(value, format, value_str);
		if (!value_str)
			return (0);
		value_str = apply_sign_flags_di(value, format, value_str);
		if (!value_str)
			return (0);
		value_str = apply_width_di(format, value_str);
		if (!value_str)
			return (0);
	}
	else
	{
		// convertir valor dependiendo de las especificaciones
	}
	// almacenar en la lista y retornar un 1
}
