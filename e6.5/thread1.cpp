#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool printa = true;

void print(char ch, bool flag){    
    for(int i = 0; i < 10; i++){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [flag]{
            return printa == flag;
        });
        std::cout << ch;
        printa = !printa;
        mtx.unlock();
        cv.notify_all();
    }
}

int main(){
    std::thread t1(print, 'a', true);
    std::thread t2(print, 'b', false);
    t1.join();
    t2.join();
    return 0;
}


