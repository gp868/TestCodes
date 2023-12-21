#include <iostream>
using namespace std;

void* memcopy(void* dest, const void* src, int n){
    char* d = (char*)dest;
    char* s = (char*)src;
    for(int i = 0; i < n; i++){
        *d++ = *s++;
    }
    return dest;
}

int main(){
    char src[] = "Hello, World!";
    char dest[20];
    memcopy(dest, src, sizeof(src));
    cout << "Source string: " << src << endl;
    cout << "Destination string: " << dest << endl;
    return 0;
}