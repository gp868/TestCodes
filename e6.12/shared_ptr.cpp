#include <iostream>

template<typename T>
class shared_ptr{
public:
    shared_ptr(T* ptr): m_ptr(ptr), m_count(new int(1)){}

    shared_ptr(shared_ptr<T>& other): m_ptr(other.m_ptr), m_count(other.m_count){
        ++(*m_count);
    }

    ~shared_ptr(){
        if(--(*m_count) == 0){
            delete m_ptr;
            delete m_count;
        }
    }

    shared_ptr<T>& operator=(shared_ptr<T>& other){
        if(this != &other){
            if(--(*m_count) == 0){
                delete m_ptr;
                delete m_count;
            }
            m_ptr = other.m_ptr;
            m_count = other.m_count;
            ++(*m_count);
        }
        return *this;
    }

    T& operator*(){
        return *m_ptr;
    }
    
    T& operator->(){
        return m_ptr;
    }

    int getusercount(){
        return *m_count;
    }

private:
    T* m_ptr;
    int* m_count;
};



