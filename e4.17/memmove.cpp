#include <iostream>
using namespace std;

void* memmove(void* dest, const void* src, int n){
    char* d = (char*)dest;
    const char* s = (const char*)src;
    if(d < s){
        *d++ = *s++;
    }else{
        char* lastd = d + (n - 1);
        char* lasts = (char*)s + (n - 1);
        for(int i = n - 1; i >= 0; i--){
            *lastd-- = *lasts--;
        }
    }
    return dest;
}


int main(){
    char s[] = "Hello, world!";
    cout << "Before: " << s << endl;
    memmove(s + 2, s, 7);
    cout << "After: " << s << endl;
    return 0;
}
