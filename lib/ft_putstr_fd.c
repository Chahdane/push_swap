#include <unistd.h>

int ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, char c)
{
	write (1, str, ft_strlen(str));
	if (c != '0')
		write(1, &c, 1);
	write(1, "\n", 1);
}