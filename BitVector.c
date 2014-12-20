/*
	Austin Herring
	August 3, 2014

	BitVector.c
	An implementation of a BitVector data type with zero-indexing and an arbitrary number of bits.
*/

#include <stdlib.h>
#include <string.h>

#include "BitVector.h"

void INITIALIZE(BitVector *bv, size_t num_bits)
{
	size_t units = ((num_bits - 1) / BITS_PER_UNIT) + 1;
	bv->bits = calloc(units, sizeof *bv->bits);
	bv->units = units;
}

void FREE_BITVECTOR(BitVector *bv)
{
	free(bv->bits);
}

void INVERT_ALL_BITS(BitVector *bv)
{
	size_t i;
	for (i = 0; i < bv->units; i++)
	{
		bv->bits[i] ^= MAX_UNIT_VALUE;
	}
}

void SET_ALL_BITS(BitVector *bv)
{
	memset(bv->bits, MAX_UNIT_VALUE, bv->units * sizeof *bv->bits);
}

void UNSET_ALL_BITS(BitVector *bv)
{
	memset(bv->bits, 0, bv->units * sizeof *bv->bits);
}

void SET_BIT(BitVector *bv, size_t bit_num)
{
	size_t unit = bit_num / BITS_PER_UNIT;
	size_t bit = bit_num % BITS_PER_UNIT;

	bv->bits[unit] |= 1 << bit;
}

void UNSET_BIT(BitVector *bv, size_t bit_num)
{
	size_t unit = bit_num / BITS_PER_UNIT;
	size_t bit = bit_num % BITS_PER_UNIT;

	bv->bits[unit] &= ~(1 << bit);
}

void INVERT_BIT(BitVector *bv, size_t bit_num)
{
	size_t unit = bit_num / BITS_PER_UNIT;
	size_t bit = bit_num % BITS_PER_UNIT;

	bv->bits[unit] ^= (1 << bit);
}

unsigned short GET_BIT(BitVector *bv, size_t bit_num)
{
	size_t unit = bit_num / BITS_PER_UNIT;
	size_t bit = bit_num % BITS_PER_UNIT;

	return bv->bits[unit] & (1 << bit) ? 1 : 0;
}
