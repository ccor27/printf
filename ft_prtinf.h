#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
typedef struct t_format
{
	int		flag_minus;
	int		flag_zero;
	int		flag_plus;
	int		flag_space;
	int		flag_hash;
	int		width;
	int		precision;
	int		has_precision;
	char	specifier;
}			t_format;
int			ft_is_valid_character(char c);
int			ft_is_flag(char c);
char		*ft_scan(char *ptr, t_list **list, va_list args);
char		*ft_get_flags(char *ptr, t_format *format);
char		*ft_get_width(char *ptr, t_format *format);
char		*ft_get_precision(char *ptr, t_format *format);
char		*ft_read_format_specifier(char *ptr, t_format *format);
int			ft_convert_arg(t_list **list, t_format *format, va_list args);
int			ft_printf(const char *string, ...);
#endif
