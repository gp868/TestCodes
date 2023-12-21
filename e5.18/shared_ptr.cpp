#include <iostream>
using namespace std;

template <typename T>
class shared_ptr{
public:
    shared_ptr(T* ptr): m_ptr(ptr), m_count(new int(1)){}

    shared_ptr(const shared_ptr<T>& other): m_ptr(other.m_ptr), m_count(other.m_count){
        ++(*m_count);
    }

    ~shared_ptr(){
        if(--(*m_count) == 0){
            delete m_ptr;
            delete m_count;
        }
    }

    shared_ptr<T>& operator=(const shared_ptr<T>& other){
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
    
    T& operator*() const{
        return *m_ptr;
    }

    T& operator->() const{
        return m_ptr;
    }

    int getCount() const{
        return *m_count;
    }

private:
    T* m_ptr;
    int* m_count;
};

int main(){
    shared_ptr<int> sp1(new int(44));
    cout << "引用计数为" << sp1.getCount() << " sp1: " << *sp1 << endl;
    shared_ptr<int> sp2(sp1);
    cout << "引用计数为" << sp2.getCount() << " sp2: " << *sp2 << endl;
    shared_ptr<int> sp3 = sp1;
    cout << "引用计数为" << sp3.getCount() << " sp3: " << *sp3 << endl;
    return 0;
}