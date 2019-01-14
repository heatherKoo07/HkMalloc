#include <stdio.h>

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include "HKMalloc.h"

void test_malloc(size_t num) {
    void* chunk = malloc(16*1024*1024);
    HKMalloc hk(chunk, 16*1024*1024);

    std::unordered_map<void*, size_t> ptrs;

    for (size_t ii=0; ii<num; ++ii) {
        size_t rr = (std::rand() % 24) + 8;
        void* ptr = hk.malloc(rr);
        memset(ptr, (rr-8) + 'a', rr);

        if (ii % 2 == 0) {
            ptrs.insert( std::make_pair(ptr, rr) );
        } else {
            hk.free(ptr);
        }
    }

    char temp[64];
    for (auto& entry: ptrs) {
        void* ptr = entry.first;
        size_t len = entry.second;
        memset(temp, (len-8) + 'a', len);
        assert( !memcmp(temp, ptr, len) );
        hk.free(ptr);
    }

    free(chunk);
}

int main() {
    test_malloc(1000);
    printf("SUCCESS!\n");
    return 0;
}
