//
// Created by Heather Hyunkyung Koo on 1/21/19.
//

#ifndef HKMALLOC_HKMALLOC_REV_H
#define HKMALLOC_HKMALLOC_REV_H

#include <cstddef>
#include <vector>
#include <list>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <math.h>

using namespace std;

class HkMalloc {
public:
    HkMalloc(void *ptr, size_t len);
    void *malloc(size_t len);
    void free(void *ptr);

private:
    const int MinSize = 32; // byte
    vector<list<void*>> listV;
    void* initP;
    size_t initLen;
    unordered_map<void*, size_t> mp;

};

HkMalloc::HkMalloc(void *ptr, size_t len) {
    initP = ptr, initLen = len;
    void* start = ptr, *mover = ptr;
    int size = MinSize;
    size_t listLen = len/2;
    list<void*> ptrList;

    while (listLen > size) {
        ptrList.push_front(mover);
        mover = (char*)mover + size;
        if ((char*)mover - (char*)start == listLen) {
            listV.push_back(ptrList);
            ptrList.clear();
            start = mover;
            size *= 2;
            listLen /= 2;
        }
    }

    while (mover < (char*)ptr + len) {
        ptrList.push_front(mover);
        mover = (char*)mover + size;
    }
    listV.push_back(ptrList);
}


void* HkMalloc::malloc(size_t len) {
    if (len > initLen) {
        cout << "Size is bigger than given one.\n";
        return nullptr;
    }
    int idx = (len <= MinSize)? 0 : log((len-1) / MinSize)/log(2) + 1;
    int allocatingSize = MinSize * pow(2, idx);
    if (listV[idx].empty()) {
        int nextIdx = idx;
        while (++nextIdx < listV.size() && !listV[nextIdx].empty()) {
            int divNum = MinSize * pow(2, nextIdx) / allocatingSize;

            void* p = listV[nextIdx].front();
            listV[nextIdx].pop_front();
            //auto it = listV[nextIdx].begin();
            //listV[nextIdx].erase(it);
            //void* p = *it;
            while (--divNum) {
                listV[idx].push_front(p);
                p = (char*)p + allocatingSize;
            }
            break;
        }
        if (nextIdx == listV.size()) {
            cout << "You've run out of memory.\n";
            return nullptr;
        }
    }
    void* p = listV[idx].front();
    listV[idx].pop_front();
    //auto it = listV[idx].begin();
    //listV[idx].erase(it);
    mp[p] = allocatingSize;
    return p;
}

void HkMalloc::free(void *ptr) {
    if (mp.find(ptr) == mp.end()) {
        cout << "Error! The pointer was not allocated.\n";
        return;
    }
    int idx = 0;
    size_t listLen = initLen/2;
    int posLen = (char*)ptr - (char*)initP;

    while (posLen >= listLen) {
        posLen -= listLen;
        listLen /= 2;
        idx++;
    }
    if (mp[ptr] == MinSize * pow(2, idx)) {
        listV[idx].push_front(ptr);
    } else {
        int n = MinSize * pow(2, idx) / mp[ptr];    // number of division
        int j = posLen % mp[ptr];               // (j+1)th pointer
        int i = log(mp[ptr] / MinSize)/log(2);  // actual index
        void* nearPtr = (char*)ptr - j*mp[ptr];
        int k = n;
        while (--k) {
            if (nearPtr != ptr && mp.find(nearPtr) != mp.end()) {
                listV[i].push_front(ptr);
                mp.erase(ptr);
                return;
            }
            nearPtr = (char*)nearPtr + mp[ptr];
        }
        nearPtr = (char*)ptr - j*mp[ptr];
        listV[idx].push_front(nearPtr);
        // delete divided ptrs in the list - linear search
        k = n;
        while (--k) {
            if (nearPtr != ptr) {
                for (auto it = listV[idx].begin(); it != listV[idx].end(); it++) {
                    if (*it == nearPtr) listV[idx].erase(it);
                }
            }
            nearPtr = (char*)nearPtr + mp[ptr];
        }
    }
    mp.erase(ptr);
}

#endif //HKMALLOC_HKMALLOC_REV_H
