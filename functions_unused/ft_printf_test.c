#include "ft_prtinf.h"

/*static void ft_print_list(t_list *list)
{
	while(list)
	{
		ft_putstr_fd(list->content,1);
		list = list->next;
	}
}
int	ft_printf(const char *string, ...)
{
	va_list	args;
	int i;

	i = 0;
	if (!string || *string == '\0')
		return (0);
	t_list *list; // lista para almacenar las palabras
	list= NULL;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			// guardar el texto hasta el momento
			ft_add_to_list(ft_substr(string,i,sizeof(string)-i),&list);
			i=0;
			string = ft_scan((char*)string, &list, args);
			if (!string)
				return (0); // hubo  un error,ver como cerrar todo de manera limpia
		}
		string++;
		i++;
	}
	va_end(args);
	ft_print_list(list);
	return(1);
}*/
