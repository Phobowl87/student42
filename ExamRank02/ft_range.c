#include <stdlib.h>

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int     *ft_range(int start, int end)
{
	int i = 0;
  	int len = abs((end - start)) + 1;
  	int *res; 
  	res = (int *)malloc(sizeof(int) * len);
  
  	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}

