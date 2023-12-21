#include <iostream>
using namespace std;

int main(){
    int n = 0x12345678;
    char* p = nullptr;
    p = (char*)&n;
    if(*p = 0x78){
        cout << "小端字节序" << endl;
    }else{
        cout << "大端字节序" << endl;
    }
    return 0;
}
