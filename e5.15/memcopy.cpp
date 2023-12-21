#include <iostream>
using namespace std;

void* memcpy(void* dest, const void* src, int n){
    char* d = (char*)dest;
    const char* s = (const char*)src;
    for(int i = 0; i < n; i++){
        *d++ = *s++;
    }
    return dest;
}

int main() {
    char src[] = "Hello, world!";
    char dest[20];
    memcpy(dest, src, sizeof(src));
    cout << "Source string: " << src << endl;
    cout << "Destination string: " << dest << endl;
    return 0;
}
