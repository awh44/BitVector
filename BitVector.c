/*
	Austin Herring
	August 3, 2014

	BitVector.c
	An implementation of a BitVector data type with zero-indexing and an arbitrary number of bits.
*/

#include <stdlib.h>
#include <string.h>

#include "BitVector.h"

#define BITVECTOR_GET_UNIT_BIT(unit, bit, bit_num)\
	unit = bit_num / BITVECTOR_BITS_PER_UNIT;\
	bit = bit_num % BITVECTOR_BITS_PER_UNIT;

const uint8_t BITVECTOR_BITS_PER_UNIT = 8;
const uint8_t BITVECTOR_MAX_UNIT_VALUE = 0xff;

void bitvector_initialize(bitvector_t *bv, size_t num_bits)
{
	size_t units = ((num_bits - 1) / BITVECTOR_BITS_PER_UNIT) + 1;
	bv->bits = calloc(units, sizeof *bv->bits);
	bv->units = units;
}

void bitvector_uninitialize(bitvector_t *bv)
{
	free(bv->bits);
}

void bitvector_invert_all_bits(bitvector_t *bv)
{
	size_t i;
	for (i = 0; i < bv->units; i++)
	{
		bv->bits[i] ^= BITVECTOR_MAX_UNIT_VALUE;
	}
}

void bitvector_set_all_bits(bitvector_t *bv)
{
	memset(bv->bits, BITVECTOR_MAX_UNIT_VALUE, bv->units * sizeof *bv->bits);
}

void bitvector_unset_all_bits(bitvector_t *bv)
{
	memset(bv->bits, 0, bv->units * sizeof *bv->bits);
}

void bitvector_set_bit(bitvector_t *bv, size_t bit_num)
{
	size_t unit, bit;
	BITVECTOR_GET_UNIT_BIT(unit, bit, bit_num);

	bv->bits[unit] |= 1 << bit;
}

void bitvector_unset_bit(bitvector_t *bv, size_t bit_num)
{
	size_t unit, bit;
	BITVECTOR_GET_UNIT_BIT(unit, bit, bit_num);

	bv->bits[unit] &= ~(1 << bit);
}

void bitvector_invert_bit(bitvector_t *bv, size_t bit_num)
{
	size_t unit, bit;
	BITVECTOR_GET_UNIT_BIT(unit, bit, bit_num);

	bv->bits[unit] ^= 1 << bit;
}

unsigned short bitvector_get_bit(bitvector_t *bv, size_t bit_num)
{
	size_t unit, bit;
	BITVECTOR_GET_UNIT_BIT(unit, bit, bit_num);

	return bv->bits[unit] >> bit & 1;
}
