#include "JAGU.h"

int JAGU::Gauss(int n)
{
	return (((n + 1) * n) / 2);
}

int JAGU::Gauss2(int n)
{
	if (n == 1)
		return 1;
	else
		return (n)+Gauss2(n - 1);
}

int JAGU::Factorial(int n)
{
	if (n == 1)
		return 1;

	return (n)*Factorial(n - 1);
}

int JAGU::Factorial2(int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		n *= i;
	}

	return n;
}
