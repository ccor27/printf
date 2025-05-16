#include "ft_prtinf.h"

int	ft_handle_percentage()
{
	char	*value;

	value = ft_strdup("%");
	if (!value)
		return (0);
	ft_putchar_fd('%',1);
	return(1);
}
int	ft_handle_string(char *string)
{
	int	count;

	if (!string)
		return (ft_putstr_fd("(null)", 1));
	count = 0;
	count += ft_putstr_fd(string, 1);
	return (count);
}
int	ft_handle_character(char c)
{
	//validate the case to allow \n and more like that
	if(!ft_isprint(c))
	 return(0);
	ft_putchar_fd(c,1);
	return(1);
}
