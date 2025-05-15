#include "ft_prtinf.h"

int ft_handle_percentage(t_list **list)
{
	char *value;

	value = ft_strdup("%");
	if(!value)
		return(0);
	return(ft_add_to_list(value,list));
}
int ft_handle_string(t_list **list, char *string)
{
	if(!string)
		return(0);
	return(ft_add_to_list(string,list));
}
int ft_handle_character(t_list **list, char c)
{
	char *value[2];

	value[0] = c;
	value[1] = '\0';
	return(ft_add_to_list(value,list));
}
