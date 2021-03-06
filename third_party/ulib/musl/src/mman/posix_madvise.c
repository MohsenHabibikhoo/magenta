#define _GNU_SOURCE
#include "syscall.h"
#include <sys/mman.h>

int posix_madvise(void* addr, size_t len, int advice) {
    if (advice == MADV_DONTNEED)
        return 0;
    return -__syscall(SYS_madvise, addr, len, advice);
}
