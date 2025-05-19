#include "ft_printf_bonus.h"

int	ft_handle_percentage(void)
{
	char	*value;

	value = ft_strdup("%");
	if (!value)
		return (0);
	ft_putchar_fd('%', 1);
	return (1);
}
