#include "ft_prtinf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret_std, ret_custom;

    // %c
    ret_std = printf("STD: %c\n", 'A');
    ret_custom = ft_printf("FT : %c\n", 'A');
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %s
    ret_std = printf("STD: %s\n", "Hola mundo");
    ret_custom = ft_printf("FT : %s\n", "Hola mundo");
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %p
    void *ptr = &ret_std;
    ret_std = printf("STD: %p\n", ptr);
    ret_custom = ft_printf("FT : %p\n", ptr);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %d
    ret_std = printf("STD: %d\n", -42);
    ret_custom = ft_printf("FT : %d\n", -42);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %i
    ret_std = printf("STD: %i\n", 1234);
    ret_custom = ft_printf("FT : %i\n", 1234);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %u
    ret_std = printf("STD: %u\n", 4294967295u);
    ret_custom = ft_printf("FT : %u\n", 4294967295u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %x
    ret_std = printf("STD: %x\n", 3735928559u); // deadbeef
    ret_custom = ft_printf("FT : %x\n", 3735928559u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %X
    ret_std = printf("STD: %X\n", 3735928559u); // DEADBEEF
    ret_custom = ft_printf("FT : %X\n", 3735928559u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // %%
    ret_std = printf("STD: %%\n");
    ret_custom = ft_printf("FT : %%\n");
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    // Edge case: NULL string
    /*ret_std = printf("STD: %s\n", (char *)NULL);
    ret_custom = ft_printf("FT : %s\n", (char *)NULL);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);*/

    // Edge case: INT_MAX and INT_MIN
    ret_std = printf("STD: %d | %d\n", INT_MAX, INT_MIN);
    ret_custom = ft_printf("FT : %d | %d\n", INT_MAX, INT_MIN);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_custom);

    return 0;
}
