#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
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
void		ft_get_flags(char **ptr, t_format *format);
void		ft_get_width(char **ptr, t_format *format);
void		ft_get_precision(char **ptr, t_format *format);
int			ft_is_valid_specifier(char c);
int			ft_scan(char **ptr, va_list args);
int			ft_handle_percentage(void);
int			ft_scan_specifier(char **ptr, t_format *format);
/*char		*ft_scan_specifier(char *ptr, t_format *format);
int			ft_convert_arg(t_list **list, t_format *format, va_list args);
void		ft_add_to_list_(char *str, t_list **list);
int			ft_handle_di(t_format *format, t_list **list, int value);
int	ft_handle_unsigned_int(t_format *format, t_list **list,
				unsigned int value);*/
int			ft_printf(const char *string, ...);
#endif
