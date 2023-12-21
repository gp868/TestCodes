

void* memcpy(void* dest, const void* src, size_t n){
    char* d = (char*)dest;
    const char* s = (const char*)src;
    for(size_t i = 0; i < n; i++){
        *d++ = *s++;
    }
    return dest;
}

void* memove(void* dest, const void* src, size_t n){
    char* d = (char*)dest;
    const char* s = (const char*)src;
    if(d < s){
        for(size_t i = 0; i < n; i++){
            *d++ = *s++;
        }
    }else{
        char* lastd = d + (n - 1);
        char* lasts = (char*)s + (n - 1);
        for(size_t i = n - 1; i >= 0; i--){
            *lastd-- = *lasts--;
        }
    }
    return dest;
}