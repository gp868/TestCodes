#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int flag = 0;

void printa(){
    for(int i = 0; i < 10; i++){
        mtx.lock();
        while(flag == 1){
            mtx.unlock();
            this_thread::yield();
            mtx.lock();
        }
        cout << "a";
        flag = 1;
        mtx.unlock();
    }
}

void printb(){
    for(int i = 0; i < 10; i++){
        mtx.lock();
        while(flag == 0){
            mtx.unlock();
            this_thread::yield();
            mtx.lock();
        }
        cout << "b";
        flag = 0;
        mtx.unlock();
    }
}

int main(){
    thread t1(printa);
    thread t2(printb);
    t1.join();
    t2.join();
    return 0;
}
