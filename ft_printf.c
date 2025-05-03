#include "ft_prtinf.h"

//funcion donde se hara el escaneo del specifier
int ft_scan(char *ptr,t_list list)
{

}

int ft_printf(const char *string, ...)
{
	if(!string || *string=='\0')
	  return(0);
	char *ptr = string;
	t_list list; //lista para almacenar las palabras
	va_list args;
	va_start(args,string);
	while(*string)
	{
		if(*string=='%')
		{
			ft_scan(string, list);
		}
		string++;
	}
	va_end(args);
}
