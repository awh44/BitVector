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

//initialize the BitVector to hold num_bits number of bits
void bitvector_initialize(BitVector *bv, size_t num_bits);
//free the BitVector
void bitvector_uninitialize(BitVector *bv);
//invert every bit in the BitVector bv
void bitvector_invert_all_bits(BitVector *bv);
//set every the BitVector to 1
void bitvector_set_all_bits(BitVector *bv);
//zero the BitVector
void bitvector_unset_all_bits(BitVector *bv);
//set the bit at bit_num (with zero-indexing) to 'true' (i.e., 1)
void bitvector_set_bit(BitVector *bv, size_t bit_num);
//set the bit at bit_num  to 'false' (i.e., 0)
void bitvector_unset_bit(BitVector *bv, size_t bit_num);
//toggle the bit in the given position - i.e, 1 goes to 0, 0 to 1
void bitvector_invert_bit(BitVector *bv, size_t bit_num);
//get the truth value of the bit at bit_num, either 0 or 1
unsigned short bitvector_get_bit(BitVector *bv, size_t bit_num);

#endif
