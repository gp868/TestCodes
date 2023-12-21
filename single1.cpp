#include<pthread.h>

class single{
public:
    static single* getinstance();

private:
    static pthread_mutex_t lock;
    static single* p;
    single(){
        pthread_mutex_init(&lock, nullptr);
    }
    ~single(){}


};
single* single::p = nullptr;
pthread_mutex_t single::lock;
single* single::getinstance(){
    if(p == nullptr){
        pthread_mutex_lock(&lock);
        if(p == nullptr){
            p = new single();
        }
        pthread_mutex_unlock(&lock);
    }
    return p;
}