#include<unistd.h>
#include<stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	isaret;
	int	res;

	i = 0;
	isaret = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isaret *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * isaret);
}
