/*
	Austin Herring
	August 3, 2014

	BitVector.h
	An implementation of a BitVector data type with zero-indexing and an arbitrary number of bits.
*/
#ifndef _BIT_VECTOR_H_
#define _BIT_VECTOR_H_

#include <stdint.h>


typedef struct
{
	uint8_t *bits;
	size_t units;
} BitVector;

/*
	initializes the BitVector to handle the given number of elements, num_bits; should be called
	before using the BitVector
	@param bv the BitVector to initialize
	@param num_bits the number of bits the BitVector is to be able to handle
*/
void bitvector_initialize(BitVector *bv, size_t num_bits);

/*
	handles unitializing the BitVector; should be called after the BitVector is done with
	@param bv the BitVector to uninitialize
*/
void bitvector_uninitialize(BitVector *bv);

/*
	invert every bit in the BitVector bv; every 1 goes to 0, every 0 goes to 1
	@param bv the BitVector whose bits are to be inverted
*/
void bitvector_invert_all_bits(BitVector *bv);

/*
	set every bit in the BitVector to 1
	@param bv the BitVector whose bits are to be set to 1
*/
void bitvector_set_all_bits(BitVector *bv);

/*
	zeros the BitVector, setting every bit to 0
	@param bv the BitVector whose bits are to be set to 0
*/
void bitvector_unset_all_bits(BitVector *bv);

/*
	set the bit at bit_num to 1
	@param bv the BitVector which is to have a bit set
	@param bit_num the particular bit which is to be set
*/
void bitvector_set_bit(BitVector *bv, size_t bit_num);

/*
	set the bit at bit_num to 0
	@param bv the BitVector which is to have a bit unset
	@param bit_num the particular bit which is to be unset
*/
void bitvector_unset_bit(BitVector *bv, size_t bit_num);

/*
	toggle the bit in the given position - if 1, set to 0; if 0, set to 1
	@param bv the BitVector which is to have a bit inverted
	@param bit_num the particular bit which is to be inverted
*/
void bitvector_invert_bit(BitVector *bv, size_t bit_num);

/*
	get the truth value of the bit at bit_num, either 0 or 1
	@param bv the BitVector from which to get the value
	@param bit_num the particular bit which is to be gotten
	@return the truth value of bit bit_num in bv, either 0 or 1
*/
unsigned short bitvector_get_bit(BitVector *bv, size_t bit_num);

#endif
