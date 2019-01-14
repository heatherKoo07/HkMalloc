#pragma once

#include <cstdlib>

class HkMalloc {
public:
    HkMalloc(void* ptr, size_t len) {}

    void* malloc(size_t len) { return ::malloc(len); }
    void free(void* ptr) { ::free(ptr); }
};
