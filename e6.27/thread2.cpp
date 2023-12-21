#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool odd = true;

void print(std::vector<int>& nums, bool flag){
    for(int i = 0; i < nums.size(); i++){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{
            return odd == flag;
        });
        if((odd && nums[i] % 2 == 1) || (!odd && nums[i] % 2 == 0)){
            std::cout << nums[i] << ' ';
        }
        odd = !odd;
        lock.unlock();
        cv.notify_all();
    }
}

int main(){
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9};
    std::thread t1(print, std::ref(nums), true);
    std::thread t2(print, std::ref(nums), false);
    t1.join();
    t2.join();
    return 0;
}

