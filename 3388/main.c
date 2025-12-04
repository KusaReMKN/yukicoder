#include <stdio.h>

static int
isPrime(int n)
{
	int i, yes;

	yes = n > 1;
	for (i = 2; i*i <= n; i++)
		if (n % i == 0) {
			yes = 0;
			break;
		}

	return yes;
}

static long
solve(int a, int b)
{
	int i;
	long res;

	res = 0;
	for (i = a; i <= b; i++)
		if (isPrime(i))
			res += (long)i*i*i - i*i + i + 1;

	return res;
}

int
main(void)
{
	int a, b, i;
	long v[10101] = { 0 };

	for (a = 1; a <= 100; a++)
		for (b = 1; b <= 100; b++)
			v[a*100+b] = solve(a, b);

	printf("long v[] = {\n");
	for (i = 0; i < 10101; i++)
		printf("%ld,\n", v[i]);
	printf("}\n");

	return 0;
}
