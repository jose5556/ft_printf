#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	/* printf("%d\n", printf("%%%d%%%s\n", 1,"nn"));
	ft_printf("%d\n", ft_printf("%%%d%%%s\n", 1,"nn")); */
	ft_printf("%d\n", ft_printf("%d%%%s\n", 100, " of 42 is 42!"));
	printf("%d\n", printf("%d%%%s\n", 100, " of 42 is 42!"));
}