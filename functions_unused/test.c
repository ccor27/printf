/*#include "ft_prtinf.h"
#include <stdlib.h>

// Funciones auxiliares ft_strlen, ft_strdup, ft_lstnew, ft_lstadd_back (asumimos que existen)

// Función para aplicar el padding de precisión
static char *apply_precision_di(int value, t_format *format, char *str_value)
{
    if (format->has_precision && format->precision > ft_strlen(str_value))
    {
        int padding_zeros = format->precision - ft_strlen(str_value);
        char *padded_str = malloc(padding_zeros + ft_strlen(str_value) + 1);
        if (!padded_str)
            return (free_and_return_null(str_value));
        int i = 0;
        if (value < 0)
            padded_str[i++] = '-';
        ft_memset(padded_str + i, '0', padding_zeros);
        char *value_to_copy = str_value;
        if (value < 0)
            value_to_copy++; // Avanzar el puntero para omitir el signo
        ft_strlcpy(padded_str + i, value_to_copy, ft_strlen(value_to_copy) + 1);
        free(str_value);
        return (padded_str);
    }
    else if (format->has_precision && format->precision == 0 && value == 0)
    {
        free(str_value);
        return (ft_strdup("0"));
    }
    return (str_value);
}

// Función para aplicar el padding de ancho
static char *apply_width_di(t_format *format, char *str_value)
{
    int width = format->width;
    int str_len = ft_strlen(str_value);
    if (width > str_len)
    {
        char *padded_str = malloc(width + 1);
        if (!padded_str)
            return (free_and_return_null(str_value));
        padded_str[width] = '\0';
        if (format->flag_minus)
            ft_memcpy(padded_str, str_value, str_len + 1);
        else
            ft_memcpy(padded_str + (width - str_len), str_value, str_len + 1);
        char padding_char;
        if(format->flag_zero && !format->has_precision)
         padding_char = '0';
        else
         padding_char=' ';
        if(format->flag_minus)
         ft_memset(padded_str +  str_len, padding_char, width - str_len);
        else
         ft_memset(padded_str, padding_char, width - str_len);
        free(str_value);
        return (padded_str);
    }
    return (str_value);
}

// Función para aplicar los flags de signo (+ y espacio)
static char *apply_sign_flags_di(int value, t_format *format, char *str_value)
{
    if (value >= 0)
    {
        if (format->flag_plus)
            str_value = ft_strjoin_free("+", str_value, ft_true);
        else if (format->flag_space)
            str_value = ft_strjoin_free(" ", str_value, ft_true);
    }
    return (str_value);
}

// Función principal para manejar la conversión de enteros (d e i)
int ft_handle_di(char specifier, t_format *format, int value)
{
    char    *str_value;
    t_list  *node;

		//validar min y max de int
	if (value < -2147483648  || value > 2147483647)
		return NULL;
    str_value = ft_itoa(value);

    if (!str_value)
        return (0);

    str_value = apply_precision_di(value, format, str_value);
    if (!str_value)
        return (0);

    str_value = apply_sign_flags_di(value, format, str_value);
    if (!str_value)
        return (0);

    str_value = apply_width_di(format, str_value);
    if (!str_value)
        return (0);

    node = ft_lstnew(str_value);
    if (!node)
        return (free_and_return_null(str_value));

    ft_lstadd_back(g_list, node); // Suponiendo que g_list es global o accesible
    return (1);
}

// Función auxiliar para liberar memoria y retornar NULL
static char *free_and_return_null(char *ptr)
{
    if (ptr)
        free(ptr);
    return (NULL);
}

// Función auxiliar para concatenar y liberar (asumimos que existe)
char    *ft_strjoin_free(char *s1, char *s2, int free_s2);
void    ft_memcpy(void *dst, const void *src, size_t n);
void    ft_memset(void *b, int c, size_t len);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstnew(void *content);
int     ft_true(void); // Asumimos que existe y retorna 1
//------------------------------------------------------------------

int	ft_handle_di(char specifier, t_format *format, int value)
{
	char	*value_str;

	// validar min y max de int
	if (value < -2147483648 || value > 2147483647)
		return (NULL);
	if (specifier == 'd')
	{
		// convertir valor dependiendo de las especificaciones
		value_str = ft_itoa(value);
		if (!value_str)
			return (0);
		value_str = apply_precision_di(value, format, value_str);//para int y dec
		if (!value_str)
			return (0);
		value_str = apply_sign_flags_di(value, format, value_str);
		if (!value_str)
			return (0);
		value_str = apply_width_di(format, value_str);
		if (!value_str)
			return (0);
	}
	else
	{
		// convertir valor dependiendo de las especificaciones
	}
	// almacenar en la lista y retornar un 1
}*/
//----------------------------------------------------------------------
