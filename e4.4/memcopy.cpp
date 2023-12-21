#include <iostream>
using namespace std;

void* memcopy(void* dest, const void* src, size_t n){
    char * d = (char *)dest;
    const char* s = (const char*)src;
    for(size_t i = 0; i < n; i++){
        *d++ = *s++;
    }
    return dest;
}

int main(){
    char s[] = "Hello, World!";
    char d[20];
    size_t n = sizeof(s) / sizeof(s[0]);
    memcopy(d, s, n);
    cout << "Source: " << s << endl;
    cout << "Destination: " << d << endl;
    return 0;
}


