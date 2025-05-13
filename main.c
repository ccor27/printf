#include "ft_prtinf.h"
#include <stdio.h>

int main(void)
{
	  int num1 = 42;
    int num2 = -1234;

    // Probamos la función printf para los casos de int y decimal
    printf("Prueba con %%d (entero positivo): ");
    ft_printf("El número positivo es: %d\n", num1);  // Debería imprimir: "El número positivo es: 42"

    printf("Prueba con %%d (entero negativo): ");
    ft_printf("El número negativo es: %d\n", num2);  // Debería imprimir: "El número negativo es: -1234"

    printf("Prueba con %%i (entero positivo): ");
    ft_printf("El número positivo es: %i\n", num1);  // Debería imprimir: "El número positivo es: 42"

    printf("Prueba con %%i (entero negativo): ");
    ft_printf("El número negativo es: %i\n", num2);  // Debería imprimir: "El número negativo es: -1234"

    return 0;
}
