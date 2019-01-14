#include "hkmalloc.h"

//#include "dummy_malloc.h"

#include "test_common.h"

#include <stdio.h>

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unordered_set>



int rnd_alloc_test(size_t size) {
    void* chunk = malloc(size);
    HkMalloc hk(chunk, size);

    std::unordered_map<void*, size_t> ptrs;

    for (size_t alc_size = 0; alc_size < size/2; ) {
        size_t rr = (std::rand() % 4096) + 8;
        void* ptr = hk.malloc(rr);
        CHK_NONNULL(ptr);
        alc_size += rr;

        memset(ptr, ((rr-8) % 26) + 'a', rr);

        size_t rr2 = std::rand() % 2;
        if (rr2) {
            ptrs.insert( std::make_pair(ptr, rr) );
        } else {
            hk.free(ptr);
        }
    }

    char temp[8192];
    for (auto& entry: ptrs) {
        void* ptr = entry.first;
        size_t len = entry.second;
        memset(temp, ((len-8) % 26) + 'a', len);
        CHK_Z( memcmp(temp, ptr, len) );
        hk.free(ptr);
    }

    free(chunk);

    return 0;
}

int fragmentation_test(size_t size) {
    void* chunk = malloc(size);
    HkMalloc hk(chunk, size);

    std::unordered_set<void*> ptrs;

    for (size_t alc_size = 0; alc_size < size / 2; ) {
        void* ptr = hk.malloc(8);
        alc_size += 8;
        ptrs.insert(ptr);
    }

    for (auto& entry: ptrs) {
        void* ptr = entry;
        hk.free(ptr);
    }

    void* ptr = hk.malloc(size - 4096);
    CHK_NONNULL(ptr);

    free(chunk);

    return 0;
}

int main(int argc, char** argv) {
    TestSuite ts(argc, argv);

    const size_t CHUNK_SIZE = 16*1024*1024;

    ts.doTest( "random allocation test", rnd_alloc_test,
               TestRange<size_t>( {CHUNK_SIZE} ) );

    ts.doTest( "fragmentation test", fragmentation_test,
               TestRange<size_t>( {CHUNK_SIZE} ) );

    return 0;
}
