#ifndef __MEMPOOL_H__
#define __MEMPOOL_H__

#define MAX_ALLOC_SIZE 4096
#define MIN_BLOCK_SIZE 16

#include <stddef.h>

typedef struct __fixed_mempool {
  char *mempool;
  char *linker;

  int block_sz;
  int free_cnt;
} fixed_mempool;

int fixed_memp_init(fixed_mempool *mp, int sz);

void fixed_memp_destroy(fixed_mempool *mp);

void* get_entry(fixed_mempool *mp);

int return_entry(fixed_mempool *mp, void *entrn);

#endif
