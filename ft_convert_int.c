#include "ft_prtinf.h"

int	ft_handle_int(t_list **list, int num)
{
	char	*value;

	value = ft_itoa(num);
	if (!value)
		return (0);
	return (ft_add_to_list(value, list));
}
int	ft_handle_unsigned_int(t_list **list, unsigned int num)
{
	char	*value;

	value = ft_utoa(num);
	if (!value)
		return (0);
	return (ft_add_to_list(value, list));
}
static void toLower(char *ptr)
{
	int i;

	i = 0;
	while(ptr[i])
	{
		ft_tolower(ptr[i]);
		i++;
	}
}
int	ft_handle_hexadecimal(t_list **list, unsigned int num, char c)
{
	char	*value;

	value = ft_itoa_base(num, 16);
	if (!value)
		return (0);
	if(c == 'x')
		toLower(value);
	return (ft_add_to_list(value, list));
}
int	ft_handle_pointer(t_list **list, void *ptr)
{
	char		*hexa_value;
	char		*result;

	if (!ptr)
	{
		result = ft_strdup("(nil)");
		if (!result)
			return (0);
		return (ft_add_to_list(result, list));
	}
	else
	{
		hexa_value = ft_itoa_base((int)(uintptr_t)ptr, 16);
		if (!hexa_value)
			return (0);
		result = ft_strjoin("0x", hexa_value);
		free(hexa_value);
		if (!result)
			return (0);
		return (ft_add_to_list(result, list));
	}
}
