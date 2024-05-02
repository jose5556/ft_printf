#include "ft_printf.h"

int	main(void)
{
	   printf("%d\n",    printf("a\n%x\n%p\n%%\na\n", 960, "ola"));
	ft_printf("%d\n", ft_printf("a\n%x\n%p\n%%\na\n", 960, "ola"));
}