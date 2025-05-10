#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
typedef struct t_format
{
    // Flags
    int     flag_minus;    // '-'
    int     flag_zero;     // '0'
    int     flag_plus;     // '+'
    int     flag_space;    // ' '
    int     flag_hash;     // '#'

    // Width y Precision
    int     width;         // número mínimo de caracteres
    int     precision;     // número mínimo de dígitos/caracteres
    int     has_precision; // indica si el punto '.' fue encontrado

    // Especificador
    char    specifier;     // c, s, d, x, etc.
} t_format;
int	ft_is_valid_character(char c);
int ft_is_flag(char c);
char	*ft_scan(char *ptr, t_list **list, va_list args);
char *ft_get_flags(char *ptr, t_format *format);
char *ft_get_width(char *ptr, t_format *format);
char	*ft_get_precision(char *ptr,t_format *format);
char	*ft_read_format_specifier(char *ptr, t_format *format);
int	ft_printf(const char *string, ...);
#endif
