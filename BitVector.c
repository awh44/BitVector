/*
	Austin Herring
	August 3, 2014

	BitVector.c
	An implementation of a BitVector data type with zero-indexing and an arbitrary number of bits.
*/

#include <stdlib.h>

#include "BitVector.h"

void INITIALIZE(BitVector *bv, int num_bits)
{
	int units = ((num_bits - 1) / BITS_PER_UNIT) + 1;
	bv->bits = calloc(units, sizeof *bv->bits);
}

void FREE_BITVECTOR(BitVector *bv)
{
	free(bv->bits);
}

void SET_BIT(BitVector *bv, int bit_num)
{
	int unit = bit_num / BITS_PER_UNIT;
	int bit = bit_num % BITS_PER_UNIT;

	bv->bits[unit] |= 1 << bit;
}

void UNSET_BIT(BitVector *bv, int bit_num)
{
	int unit = bit_num / BITS_PER_UNIT;
	int bit = bit_num % BITS_PER_UNIT;

	bv->bits[unit] &= ~(1 << bit);
}

void TOGGLE_BIT(BitVector *bv, int bit_num)
{
	int unit = bit_num / BITS_PER_UNIT;
   int bit = bit_num % BITS_PER_UNIT;

	bv->bits[unit] ^= (1 << bit);
}

unsigned short GET_BIT(BitVector *bv, int bit_num)
{
	int unit = bit_num / BITS_PER_UNIT;
	int bit = bit_num % BITS_PER_UNIT;

	return bv->bits[unit] & (1 << bit) ? 1 : 0;
}
