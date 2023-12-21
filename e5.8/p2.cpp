#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
int nums[] = {1,2,3,4,5,6,7,8,9};
int n = sizeof(nums) / sizeof(nums[0]);

void print_odd(){
    for(int i = 0; i < n; i += 2){
        unique_lock<mutex> lock(mtx);
        while(nums[i] % 2 == 0){
            cv.wait(lock);
        }
        cout << nums[i];
        cv.notify_all();
    }
}

void print_even(){
    for(int i = 1; i < n; i += 2){
        unique_lock<mutex> lock(mtx);
        while(nums[i] % 2 == 1){
            cv.wait(lock);
        }
        cout << nums[i];
        cv.notify_all();
    }
}

int main(){
    thread t1(print_odd);
    thread t2(print_even);
    t1.join();
    t2.join();
    return 0;
}