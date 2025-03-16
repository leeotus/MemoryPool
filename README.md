## A Simple MemoryPool Written in C
#### Usage:
```c++
#include "fixed_mempool.h"

int main(int argc, char **argv) {
  fixed_mempool mp;
  fixed_mempool_init(&mp, sizeof(xxx));

  void* ptr = get_entry(&mp);
  // do something...

  return_entry(&mp, ptr);
  return 0;
}
```