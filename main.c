#include <stdio.h>

#include "BitVector.h"

extern const uint8_t BITVECTOR_BITS_PER_UNIT;

int main()
{
	printf("How many bits would you like to test with?\n");
	int n;
	scanf("%d", &n);

	BitVector bv;	
	bitvector_initialize(&bv, n);

	printf("Setting from bit 0 to bit %d...\n", n - 1);
	int i;
	for (i = 0; i < n; i++)
	{
		bitvector_set_bit(&bv, i);
		printf("bitvector_get_bit(%d) = %u\n", i, bitvector_get_bit(&bv, i));
		printf("bv.bits[%d] = %u\n\n", i / BITVECTOR_BITS_PER_UNIT, bv.bits[i / BITVECTOR_BITS_PER_UNIT]);
	}

	printf("Enter any number to continue: ");
	int tmp;
	scanf("%d", &tmp);

	printf("\nUnsetting from bit %d to bit 0...\n", n - 1);
	for (i = n - 1; i > -1; i--)
	{
		bitvector_unset_bit(&bv, i);
		printf("bitvector_get_bit(%d) = %u\n", i, bitvector_get_bit(&bv, i));
		printf("bv.bits[%d] = %u\n\n", i / BITVECTOR_BITS_PER_UNIT, bv.bits[i / BITVECTOR_BITS_PER_UNIT]);
	}

	printf("\nBefore toggling bit 0 (bv.bits[0]): %d\n", bv.bits[0]);
	bitvector_invert_bit(&bv, 0);
	printf("After toggling bit 0 (bv.bits[0]): %d\n", bv.bits[0]);
	bitvector_invert_all_bits(&bv);
	printf("After inverting all bits (bv.bits[0]): %d\n", bv.bits[0]);
	bitvector_invert_all_bits(&bv);
	printf("After inverting all bits again (bv.bits[0]): %d\n", bv.bits[0]);
	bitvector_invert_bit(&bv, 0);
	printf("After inverting bit 0 again (bv.bits[0]): %d\n", bv.bits[0]);

	bitvector_set_all_bits(&bv);
	printf("\nAfter setting all bits (bv.bits[0]): %d\n", bv.bits[0]);

	bitvector_unset_all_bits(&bv);
	printf("After unsetting all bits (bv.bits[0]): %d\n", bv.bits[0]);

	bitvector_uninitialize(&bv);

	return 0;
}
