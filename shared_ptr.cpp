#include <iostream>
using namespace std;

template<typename T>
class shared_ptr{
public:
    // 构造函数
    shared_ptr(T* ptr): m_ptr(ptr), m_count(new int(1)){}

    // 析构函数
    ~shared_ptr(){
        if(--(*m_count) == 0){
            delete m_ptr;
            delete m_count;
        }
    }

    // 拷贝构造函数
    shared_ptr(const shared_ptr<T>& other): m_ptr(other.m_ptr), m_count(other.m_count){
        ++(*m_count);
    }

    shared_ptr<T>& operator=(const shared_ptr<T>& other){
        if(this != &other){
            if(--(*m_count) == 0){
                delete m_count;
                delete m_ptr;
            }
            m_ptr = other.m_ptr;
            m_count = other.m_count;
            ++(*m_count);
        }
        return *this;
    }

    // 重载解引用运算符
    T& operator*() const{
        return *m_ptr;
    }
    
    // 重载获取指针运算符
    T& operator->() const{
        return m_ptr;
    }

    // 获取引用计数
    int use_count() const{
        return *m_count;
    }

    // 判断指针是否为空
    bool is_null() const{
        return !m_ptr;
    }
private:
    T* m_ptr;
    int* m_count;
};

int main() {
    
    shared_ptr<int> sp1(new int(42));
    cout << "**********测试构造函数**********" << endl;
    cout << "sp1: " << *sp1 << " use count: " << sp1.use_count() << endl;

    shared_ptr<int> sp2(sp1);
    cout << "**********测试拷贝构造函数**********" << endl;
    cout << "sp2: " << *sp2 << " use count: " << sp2.use_count() << endl;

    shared_ptr<int> sp3 = sp1;
    cout << "**********测试赋值运算符**********" << endl;
    cout << "sp3: " << *sp3 << " use count: " << sp3.use_count() << endl;

    return 0;
}
