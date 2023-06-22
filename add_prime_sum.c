#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	char	result;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	result = (nb % 10) + '0';
	write(1, &result, 1);
}

int is_prime(int num)
{
	int i = 3;
	
	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return (0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int sum = 0;
		int nb = ft_atoi(argv[1]);
		while (nb > 0)
			if (is_prime(nb--))
				sum += (nb + 1);
		ft_putnbr(sum);
	}
	if (argc != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
