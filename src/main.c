#include <stdio.h>
#include "fixed_mempool.h"

int main(int argc, char **argv) {
  fixed_mempool mp;
  fixed_memp_init(&mp, 36);
  void* ptrs[100];
  for(int i=0; i<100; ++i) {
    ptrs[i] = get_entry(&mp);
    printf("%d: get_entry: %p\r\n", i, ptrs[i]);
  }
  for(int i=0;i<100;++i) {
    return_entry(&mp, ptrs[i]);
  }
  return 0;
}
