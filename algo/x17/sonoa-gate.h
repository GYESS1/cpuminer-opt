#ifndef SONOA_GATE_H__
#define SONOA_GATE_H__ 1

#include "algo-gate-api.h"
#include <stdint.h>

#if defined(__AVX512F__) && defined(__AVX512VL__) && defined(__AVX512DQ__) && defined(__AVX512BW__)
  #define SONOA_8WAY 1
#elif defined(__AVX2__) && defined(__AES__)
  #define SONOA_4WAY 1
#endif

bool register_sonoa_algo( algo_gate_t* gate );

#if defined(SONOA_8WAY)

void sonoa_8way_hash( void *state, const void *input );
int scanhash_sonoa_8way( struct work *work, uint32_t max_nonce,
                         uint64_t *hashes_done, struct thr_info *mythr );

#elif defined(SONOA_4WAY)

void sonoa_4way_hash( void *state, const void *input );
int scanhash_sonoa_4way( struct work *work, uint32_t max_nonce,
                         uint64_t *hashes_done, struct thr_info *mythr );

#else

void sonoa_hash( void *state, const void *input );
int scanhash_sonoa( struct work *work, uint32_t max_nonce,
                  uint64_t *hashes_done, struct thr_info *mythr );
void init_sonoa_ctx();

#endif

#endif
