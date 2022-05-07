#include<stdio.h>
#include<stdbool.h>
#include<unistd.h>
#include<limits.h>

int	ft_basesize(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

bool	ft_base_kontrol(char *base)
{
	char	*curr;
	int		index;
	int		jndex;

	curr = base;
	if (ft_basesize(curr) <= 1)
		return (false);
	index = 0;
	while (curr[index] != '\0')
	{
		jndex = index + 1;
		while (base[jndex] != '\0')
			if (base[index] == base[jndex++])
				return (false);
		index++;
	}
	while (*curr)
	{
		if (*curr == '\t' || *curr == '\n' || *curr == '\v' || *curr == '\f'
			|| *curr == '\r' || *curr == ' ' || *curr == '+' || *curr == '-')
			return (false);
		curr++;
	}
	return (true);
}

void	ft_putnbr_base_recursive(int number, char *base, int size)
{
	if (number == -2147483648)
	{
		ft_putnbr_base_recursive(number / size, base, size);
		write(1, &(base[-(number % size)]), 1);
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_recursive(-number, base, size);
		return ;
	}
	if (number > size - 1)
		ft_putnbr_base_recursive(number / size, base, size);
	write(1, &(base[number % size]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	if (ft_base_kontrol(base) == false)
		return ;
	size = ft_basesize(base);
	ft_putnbr_base_recursive(nbr, base, size);
}
