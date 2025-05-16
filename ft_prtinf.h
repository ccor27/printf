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
int			ft_is_valid_specifier(char c);
int			ft_is_flag(char c);
int			ft_scan(char specifier, va_list args);
char		*ft_get_flags(char *ptr, t_format *format);
char		*ft_get_width(char *ptr, t_format *format);
char		*ft_get_precision(char *ptr, t_format *format);
char		*ft_read_format_specifier(char *ptr, t_format *format);
int			ft_convert_arg(t_list **list, t_format *format, va_list args);
// void ft_add_to_list_(char *str, t_list **list);
int			ft_handle_di(t_format *format, t_list **list, int value);
// int	ft_handle_unsigned_int(t_format *format, t_list **list,
//		unsigned int value);
//char		*free_and_return_null(char *ptr);
//-----------------------new functions mandatory part-------
int ft_process_string(char *ptr, va_list	args);
int			ft_add_to_list(char *str, t_list **list);
int			ft_handle_int(int num);
int			ft_handle_unsigned_int(unsigned int num);
int			ft_handle_hexadecimal(unsigned int num, char c);
int			ft_handle_percentage();
int			ft_handle_string(char *string);
int			ft_handle_character(char c);
int			ft_handle_pointer(void *ptr);
int		ft_print_list(t_list *list);
//----------------------------------------------------------
int			ft_printf(const char *string, ...);
#endif
