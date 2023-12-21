#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>

class threadPool{
public:
    threadPool(size_t n);
    ~threadPool();
    void enqueue(std::function<void()> task);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> stop;
    void worker();
};

threadPool::threadPool(size_t n){
    for(size_t i = 0; i < n; i++){
        workers.emplace_back(worker, this);
    }
}

threadPool::~threadPool(){
    stop = false;
    cv.notify_all();
    for(auto& worker : workers){
        worker.join();
    }
}

void threadPool::enqueue(std::function<void()> task){
    std::unique_lock<std::mutex> lock(mtx);
    tasks.push(task);
    mtx.unlock();
    cv.notify_all();
}


void threadPool::worker(){
    while(!stop){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]{
            return stop || !tasks.empty();
        });
        if(tasks.empty() && stop){
            return;
        }
        std::function<void()> task = tasks.front();
        tasks.pop();
        mtx.unlock();
        task();
    }
}


