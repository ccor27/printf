#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
//-----------------------new functions mandatory part-------
int			ft_is_valid_specifier(char c);
int			ft_is_flag(char c);
int			ft_scan(char specifier, va_list args);
int			ft_process_string(char *ptr, va_list args);
int			ft_handle_int(int num);
int			ft_handle_unsigned_int(unsigned int num);
int			ft_handle_hexadecimal(unsigned int num, char c);
int			ft_handle_percentage(void);
int			ft_handle_string(char *string);
int			ft_handle_character(char c);
int			ft_handle_pointer(void *ptr);
//----------------------------------------------------------
int			ft_printf(const char *string, ...);
#endif
