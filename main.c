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
		printf("bv.bits[%d] = %u\n\n", i / BITS_PER_UNIT, bv.bits[i / BITS_PER_UNIT]);
	}

	printf("Enter any number to continue: ");
	int tmp;
	scanf("%d", &tmp);

	printf("\nUnsetting from bit %d to bit 0...\n", n - 1);
	for (i = n - 1; i > -1; i--)
	{
		UNSET_BIT(&bv, i);
		printf("GET_BIT(%d) = %u\n", i, GET_BIT(&bv, i));
		printf("bv.bits[%d] = %u\n\n", i / BITS_PER_UNIT, bv.bits[i / BITS_PER_UNIT]);
	}

	printf("\nBefore toggling bit 0: %d\n", GET_BIT(&bv, 0));
	TOGGLE_BIT(&bv, 0);
	printf("After toggling bit 0: %d\n", GET_BIT(&bv, 0));
	TOGGLE_BIT(&bv, 0);
	printf("After toggling again: %d\n", GET_BIT(&bv, 0));

	FREE_BITVECTOR(&bv);

	return 0;
}
