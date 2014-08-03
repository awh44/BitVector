#include <stdio.h>

#include "BitVector.h"

int main()
{
	printf("How many bits would you like to test with?\n");
	int n;
	scanf("%d", &n);

	BitVector bv;	
	INITIALIZE(&bv, n);

	printf("Setting from bit 0 to bit %d...\n", n - 1);
	int i;
	for (i = 0; i < n; i++)
	{
		SET_BIT(&bv, i);
		printf("GET_BIT(%d) = %u\n", i, GET_BIT(&bv, i));
		printf("bv.bits[%d] = %u\n\n", i / 32, bv.bits[i / 32]);
	}

	printf("Enter a number to continue: ");
	int tmp;
	scanf("%d", &tmp);

	printf("Unsetting from bit %d to bit 0...\n", n - 1);
	for (i = n - 1; i > -1; i--)
	{
		UNSET_BIT(&bv, i);
		printf("GET_BIT(%d) = %u\n", i, GET_BIT(&bv, i));
		printf("bv.bits[%d] = %u\n\n", i / 32, bv.bits[i / 32]);
	}

	return 0;
}
