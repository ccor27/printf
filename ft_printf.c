#include "ft_prtinf.h"

int	ft_printf(const char *string, ...)
{
	char	*ptr;
	va_list	args;

	if (!string || *string == '\0')
		return (0);
	ptr = string;
	t_list *list; // lista para almacenar las palabras
	list= NULL;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			// guardar el texto hasta el momento
			string = ft_scan(string, &list, args);
			if (!string)
				return (0); // hubo  un error,ver como cerrar todo de manera limpia

		}
		string++;
	}
	va_end(args);
}
