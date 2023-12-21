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
        }
        return *this;
    }

    T& operator*() const{
        return *m_ptr;
    }

    T& operator->() const{
        return m_ptr;
    }

    int userCount() const{
        return *m_count;
    }

private:
    T* m_ptr;
    int* m_count;
};

int main(){
    shared_ptr<int> sp1(new int(666));
    cout << *sp1 << " " << sp1.userCount() << endl;
    shared_ptr<int> sp2(sp1);
    cout << *sp2 << " " << sp2.userCount() << endl;
    shared_ptr<int> sp3 = sp1;
    cout << *sp3 << " " << sp3.userCount() << endl;
    return 0;
}