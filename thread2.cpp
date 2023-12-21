#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx; // 互斥锁
std::condition_variable cv; // 条件变量
bool print_odd = true; // 控制输出奇数与否的标志

void print_elements(std::vector<int>& arr, bool odd) {
    for (int i = 0; i < arr.size(); i++) {
        std::unique_lock<std::mutex> lock(mtx);

        // 等待适当的（奇数/偶数）
        cv.wait(lock, [odd]() {
            return print_odd == odd; 
        });

        // 验证数组中的元素是否满足奇数/偶数条件
        if ((odd && arr[i] % 2 == 1) || (!odd && arr[i] % 2 == 0)) {
            std::cout << arr[i];
        }

        print_odd = !print_odd; // 切换状态

        lock.unlock();
        cv.notify_all(); // 通知其他线程
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::thread t1(print_elements, std::ref(arr), true);  // 线程1打印奇数
    std::thread t2(print_elements, std::ref(arr), false); // 线程2打印偶数

    t1.join();
    t2.join();

    return 0;
}
