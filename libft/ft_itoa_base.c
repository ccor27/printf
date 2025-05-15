#include "libft.h"

// Function to get the number of digits in the integer for a given base
static int	ft_know_num_digits(int n, int num, int base)
{
	if (n > 0)
		return (ft_know_num_digits(n / base, num + 1, base));
	return (num);
}

// Function to handle special cases (like 0 and INT_MIN)
static char	*ft_handle_special_cases(int n, int base)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

// Function to convert integer to string for a given base
static char	*ft_convert_int_to_string(int n, int is_negative, int size, char *s,
		int base)
{
	int			total_size;
	const char	base_digits[] = "0123456789ABCDEF";

	total_size = size + is_negative;
	s[total_size] = '\0';
	while (total_size--)
	{
		s[total_size] = base_digits[n % base];
		n /= base;
	}
	if (is_negative)
		s[0] = '-';
	return (s);
}
// Main function to convert integer to string based on a given base
char	*ft_itoa_base(int n, int base)
{
	int		is_negative;
	char	*num_in_string;
	int		num_of_digits;

	if (base < 2 || base > 16)
		return (NULL);
	is_negative = 0;
	if (n == 0 || n <= -2147483648)
		return (ft_handle_special_cases(n, base));
	if (n < 0 && base == 10)
	{
		is_negative = 1;
		n = n * -1;
	}
	num_of_digits = ft_know_num_digits(n, 0, base);
	if (is_negative)
		num_in_string = malloc((num_of_digits + 2) * sizeof(char));
	else
		num_in_string = malloc((num_of_digits + 1) * sizeof(char));
	if (!num_in_string)
		return (NULL);
	return (ft_convert_int_to_string(n, is_negative, num_of_digits,
			num_in_string, base));
}
