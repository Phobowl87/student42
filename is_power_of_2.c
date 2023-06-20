int is_power_of_2(unsigned int n)
{
	int     number = 1;

        if (n == 1)
                return (1);
        if (n % 2 != 0)
                return (0);
        while (number < n)
                number *= 2;
        if (number == n)
                return (1);
        else
                return (0);

}
