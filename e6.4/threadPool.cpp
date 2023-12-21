#include <iostream>
#include <vector>
#include <queue>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <atomic>
#include <functional>

class threadPool{
public:
    threadPool(size_t num);
    ~threadPool();
    void enqueue(std::function<void()> task);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::atomic<bool> stop;
    std::condition_variable cv;
    void worker();
};

threadPool::threadPool(size_t num): stop(false){
    for(size_t i = 0; i < num; i++){
        workers.emplace_back(worker, this);
    }
}

threadPool::~threadPool(){
    stop = true;
    cv.notify_all();
    for(auto &worker : workers){
        worker.join();
    }
}


void threadPool::enqueue(std::function<void()> task){
    {
        std::unique_lock<std::mutex> lock(mtx);
        tasks.push(task);
    }
    cv.notify_all();
}


void threadPool::worker(){
    while(!stop){
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this](){
                return !tasks.empty() || stop;
            });
            if(tasks.empty() && stop){
                return;
            }
            task = tasks.front();
            tasks.pop();
        }
        task();
    }
}


int main(){
    threadPool pool(4);
    for(int i = 0; i < 10; i++){
        pool.enqueue([i]{
            std::cout << "Task " << i << " is being executed by thread "
            << std::this_thread::get_id() << std::endl;
        });
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}

