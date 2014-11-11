/*
	Austin Herring
	August 3, 2014

	BitVector.h
	An implementation of a BitVector data type with zero-indexing and an arbitrary number of bits.
*/
#ifndef _BIT_VECTOR_H_
#define _BIT_VECTOR_H_

#include <stdint.h>

#define BITS_PER_UNIT 8
#define MAX_UNIT_VALUE 255

typedef struct
{
	uint8_t *bits;
	unsigned int units;
} BitVector;

//initialize the BitVector to hold num_bits number of bits
void INITIALIZE(BitVector *bv, unsigned int num_bits);
//free the BitVector
void FREE_BITVECTOR(BitVector *bv);
//invert every bit in the BitVector bv
void INVERT_ALL_BITS(BitVector *bv);
//set every the BitVector to 1
void SET_ALL_BITS(BitVector *bv);
//zero the BitVector
void UNSET_ALL_BITS(BitVector *bv);
//set the bit at bit_num (with zero-indexing) to 'true' (i.e., 1)
void SET_BIT(BitVector *bv, unsigned int bit_num);
//set the bit at bit_num  to 'false' (i.e., 0)
void UNSET_BIT(BitVector *bv, unsigned int bit_num);
//toggle the bit in the given position - i.e, 1 goes to 0, 0 to 1
void INVERT_BIT(BitVector *bv, unsigned int bit_num);
//get the truth value of the bit at bit_num, either 0 or 1
unsigned short GET_BIT(BitVector *bv, unsigned int bit_num);

#endif
