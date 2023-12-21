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
    threadPool(size_t n):stop(false){
        for(size_t i = 0; i < n; i++){
            workers.emplace_back(worker, this);
        }
    }

    ~threadPool(){
        stop = true;
        cv.notify_all();
        for(auto& worker : workers){
            worker.join();
        }
    }
    void enqueue(std::function<void()> task){
        std::unique_lock<std::mutex> lock(mtx);
        tasks.push(task);
        lock.unlock();
        cv.notify_all();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> stop;
    void worker(){
        while(!stop){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]{
                return stop || !tasks.empty();
            });
            if(stop && tasks.empty()){
                return;
            }
            auto task = tasks.front();
            tasks.pop();
            task();   
        }
    }
};





