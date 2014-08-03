#include <stdint.h>

typedef struct
{
	uint32_t *bits;
} BitVector;

void INITIALIZE(BitVector *bv, int num_bits);
void FREE_BITVECTOR(BitVector *bv);
void SET_BIT(BitVector *bv, int bit_num);
void UNSET_BIT(BitVector *bv, int bit_num);
unsigned short GET_BIT(BitVector *bv, int bit_num);
