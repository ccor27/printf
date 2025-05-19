#include "ft_printf_bonus.h"

int ft_handle_di(t_format t_format,int num)
{
	//- , 0 , + , . , space
	char *num_string;

	num_string = ft_atoi(num);
	if(!num_string)
		return(0);
	//aplicar flags
}
