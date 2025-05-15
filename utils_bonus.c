#include "ft_prtinf.h"

int	ft_is_flag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}
char	*ft_get_flags(char *ptr, t_format *format)
{
	while (ft_is_flag(*ptr))
	{
		if (*ptr == '-')
			format->flag_minus = 1;
		else if (*ptr == '0')
			format->flag_zero = 1;
		else if (*ptr == '+')
			format->flag_plus = 1;
		else if (*ptr == ' ')
			format->flag_space = 1;
		else if (*ptr == '#')
			format->flag_hash = 1;
		ptr++;
	}
	return (ptr);
}
char	*ft_get_width(char *ptr, t_format *format)
{
	while (*ptr >= '0' && *ptr <= '9')
	{
		format->width = format->width * 10 + (*ptr - '0');
		ptr++;
	}
	return (ptr);
}
char	*ft_get_precision(char *ptr, t_format *format)
{
	format->has_precision = 1;
	ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		format->precision = format->precision * 10 + (*ptr - '0');
		ptr++;
	}
	return (ptr);
}
