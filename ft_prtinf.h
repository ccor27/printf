#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
typedef struct s_format
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
#endif
