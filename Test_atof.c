
#include <stdio.h>

static int	check_sign(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
	}
	return (sign);
}

double	my_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;

	if (!str)
		return (0);
	i = 0;
	result = 0.0;
	decimal = 1.0;
	if (str[i])
	{
		sign = check_sign(str);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		decimal *= 10;
	}
	return (sign * result / decimal);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		printf("float nbr : %f\n", my_atof(argv[1]));
		printf("float nbr : %f\n", my_atof(argv[2]));
	}
}
