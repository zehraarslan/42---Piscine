#include<stdio.h>

int	ft_strlen(char *str)
{
	int	sayac;

	sayac = 0;
	while (*str != '\0')
	{
		sayac++;
		str++;
	}
	return (sayac);
}
