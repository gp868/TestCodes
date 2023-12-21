#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

int nums[] = {1,2,3,4,5,6,7,8,9};
int n = sizeof(nums) / sizeof(nums[0]);
mutex mtx;
condition_variable cv;

void printOdd(){
    for(int i = 0; i < n; i += 2){
        unique_lock<mutex> lock(mtx);
        while(nums[i] % 2 == 0){
            cv.wait(lock);
        }
        cout << nums[i] << " ";
        cv.notify_all();
    }
}

void printEven(){
    for(int i = 1; i < n; i += 2){
        unique_lock<mutex> lock(mtx);
        while(nums[i] % 2 == 1){
            cv.wait(lock);
        }
        cout << nums[i] << " ";
        cv.notify_all();
    }
}

int main(){
    thread t1(printOdd);
    thread t2(printEven);
    t1.join();
    t2.join();
    return 0;
}
