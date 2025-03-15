#include "fixed_mempool.h"
#include <stdlib.h>

int fixed_memp_init(fixed_mempool *mp, int sz) {
  if(mp != NULL) {
    if(sz < MIN_BLOCK_SIZE)
      sz = MIN_BLOCK_SIZE;
    mp->mempool = (char *)malloc(MAX_ALLOC_SIZE);
    if(!mp->mempool) return -1;
    mp->block_sz = sz;
    mp->linker = mp->mempool;
    mp->free_cnt = MAX_ALLOC_SIZE / sz;

    char *ptr = mp->linker;
    for(int i=0;i<mp->free_cnt;++i) {
      *(char **)ptr = ptr + sz;
      ptr += sz;
    }
    *(char **)ptr = NULL;
    return 0;
  }
  return -1;
}

void fixed_memp_destroy(fixed_mempool *mp) {
  if(mp == NULL || mp->mempool == NULL) return;
  free(mp->mempool);
}

void *get_entry(fixed_mempool *mp) {
  if(mp == NULL || mp->free_cnt == 0)
    return NULL;

  void *ptr = mp->linker;
  mp->linker = *(char **)ptr;
  mp->free_cnt -= 1;

  return ptr;
}

int return_entry(fixed_mempool *mp, void *entry) {
  if(mp == NULL || entry == NULL)
    return -1;
  *(char **)entry = mp->linker;
  mp->linker = entry;
  mp->free_cnt += 1;
  return 0;
}
