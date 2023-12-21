#include <iostream>

template<typename T>
class shared_ptr{
public:
    shared_ptr(T* ptr):m_ptr(ptr), m_count(new int(1)){}

    shared_ptr(shared_ptr<T>& other):m_ptr(other.m_ptr), m_count(other.m_count){
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

    int use_count(){
        return *m_count;
    }


private:
    T* m_ptr;
    int* m_count;
};



int main() {
    
    shared_ptr<int> sp1(new int(42));
    std::cout << "**********测试构造函数**********" << std::endl;
    std::cout << "sp1: " << *sp1 << " use count: " << sp1.use_count() << std::endl;

    shared_ptr<int> sp2(sp1);
    std::cout << "**********测试拷贝构造函数**********" << std::endl;
    std::cout << "sp2: " << *sp2 << " use count: " << sp2.use_count() << std::endl;

    shared_ptr<int> sp3 = sp1;
    std::cout << "**********测试赋值运算符**********" << std::endl;
    std::cout << "sp3: " << *sp3 << " use count: " << sp3.use_count() << std::endl;

    return 0;
}
