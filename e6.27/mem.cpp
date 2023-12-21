#include <iostream>

void* memcpy(const void* src, void* dest, size_t n){
    const char* s = (const char*)src;
    char* d = (char*)dest;
    for(size_t i = 0; i < n; i++){
        *d++ = *s++;
    }
    return dest;
}

void* memove(const void* src, void* dest, size_t n){
    const char* s = (const char*)src;
    char* d = (char*)dest;
    if(d < s){
        for(size_t i = 0; i < n; i++){
            *d++ = *s++;
        }
    }else{
        char* lastd = d + (n - 1);
        char* lasts = (char*)s + (n - 1);
        for(size_t i = 0; i < n; i++){
            *lastd-- = *lasts--;
        }
    }
    return dest;
}

