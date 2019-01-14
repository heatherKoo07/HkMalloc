//
// Created by Heather Hyunkyung Koo on 1/12/19.
//

#ifndef HKMALLOC_HKMALLOC_H
#define HKMALLOC_HKMALLOC_H

#include <cstddef>
#include <utility>
#include <map>
#include <iostream>

using namespace std;

class HkMalloc {
public:
    HkMalloc(void* ptr, size_t len);
    void* malloc(size_t len);
    void free(void* ptr);

private:
    size_t len;
    multimap<size_t, void*> freed_map;
    map<void*, size_t> freed_map_for_merge;
    map<void*, size_t> allocated_map;
};


HkMalloc::HkMalloc(void *ptr, size_t len) {
    this->len = len;
    freed_map.insert({this->len, ptr});
    freed_map_for_merge.insert({ptr, this->len});
}

void* HkMalloc::malloc(size_t len) {
    void* p;
    auto eqIt = freed_map.find(len);
    auto upIt = freed_map.upper_bound(len);
    if (eqIt != freed_map.end()) {
        p = eqIt->second;
        freed_map.erase(eqIt);
    } else if (upIt != freed_map.end()) {
        p = upIt->second;
        freed_map.insert({upIt->first - len, (char*)p + len});
        freed_map_for_merge.insert({(char*)p + len, upIt->first - len});
        freed_map.erase(upIt);
    } else {
        cout << "You've run out of memory\n";
        return nullptr;
    }
    freed_map_for_merge.erase(p);
    allocated_map[p] = len;
    return p;
}

void HkMalloc::free(void *ptr) {
    if (allocated_map.find(ptr) == allocated_map.end()) {
        cout << "Error! The pointer was not allocated.\n";
        return;
    }
    void* prevP = (char*)ptr-allocated_map[ptr];
    void* nextP = (char*)ptr+allocated_map[ptr];
    auto prevIt = freed_map_for_merge.lower_bound(prevP);
    auto nextIt = freed_map_for_merge.find(nextP);
    pair <multimap<size_t,void*>::iterator, multimap<size_t,void*>::iterator> ret;

    if (prevIt == freed_map_for_merge.end() && nextIt == freed_map_for_merge.end()) {
        freed_map_for_merge.insert({ptr, allocated_map[ptr]});
        freed_map.insert({allocated_map[ptr], ptr});
    } else {
        if (prevIt != freed_map_for_merge.end()) {
            ret = freed_map.equal_range(prevIt->second);
            for (auto it = ret.first; it != ret.second; it++) {
                if (it->second == prevIt->first) {
                    freed_map.erase(it);
                    break;
                }
            }
            prevIt->second += allocated_map[ptr];       // update the length in freed_map_for_merge
            freed_map.insert({prevIt->second, prevIt->first});
        }

        if (nextIt != freed_map_for_merge.end()) {
            ret = freed_map.equal_range(nextIt->second);
            for (auto it = ret.first; it != ret.second; it++) {
                if (it->second == nextIt->first) {
                    freed_map.erase(it);
                    break;
                }
            }

            if (prevIt != freed_map_for_merge.end()) {
                ret = freed_map.equal_range(prevIt->second);
                for (auto it = ret.first; it != ret.second; it++) {
                    if (it->second == prevIt->first) {
                        freed_map.erase(it);
                        break;
                    }
                }
                prevIt->second += nextIt->second;
                freed_map.insert({prevIt->second, prevIt->first});
            } else {
                freed_map_for_merge.insert({ptr, allocated_map[ptr]+nextIt->second});
                freed_map.insert({allocated_map[ptr]+nextIt->second, ptr});
            }
            freed_map_for_merge.erase(nextIt);
        }
    }
    allocated_map.erase(ptr);
}



#endif //HKMALLOC_HKMALLOC_H
