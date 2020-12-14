#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

//float	
double	strint_tof(char *str)
{
	double	res;
	float	sign;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-' ? -1.0 : 1.0);
		i++;
	}
	while (str[i] && res < __FLT_MAX__)
	{
		res = res * 10 + str[i] - '0';
		printf("%lf\n", res);
		i++;
	}
	if (str[i])
		return (res * INFINITY);
	// printf("%f\n", res * sign);
	return (res * sign);
}

int	main(void)
{
	int		exp;
	float	f;
	double	d;
	f = 239.00211;
	frexp(f, &exp);
	printf("the float %f\n", f);
	printf("the exponent %d\n", exp);
	printf("the result %f\n", frexp(f, &exp));
	f = ldexp(frexp(f, &exp) ,exp);
	// printf("%lf\n", -340282346638528859811704183484516925441.000000);
	// printf("%d\n", signbit(-0.0));
	// f = 340282346638528859811704183484516925438.000000 + 1.0;
	// printf("%f\n", f); 
	printf("%lf\n", strint_tof("3402823466385288598117041"));
	return 0;
}
