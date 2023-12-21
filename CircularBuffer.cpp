#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class circularBuffer{
public:
    // 构造函数
    circularBuffer(size_t size): m_data(size), m_head(0), m_tail(0), m_full(false){}

    // 判断缓冲区是否为空
    bool empty() const{
        return !m_full && m_head == m_tail;
    }

    // 判断缓冲区是否已满
    bool full() const{
        return m_full;
    }

    // 获取缓冲区中元素的数量
    size_t size() const{
        size_t size = m_data.size();
        if(!m_full){
            if(m_head >= m_tail){
                size = m_head - m_tail;
            }else{
                size = m_data.size() + m_head - m_tail;
            }
        }
        return size;
    }
    
    // 向缓冲区中添加一个元素
    void push(const T& item){
        m_data[m_head] = item;
        if(m_full){
            m_tail = (m_tail + 1) % m_data.size();
        }
        m_head = (m_head + 1) % m_data.size();
        m_full = (m_head == m_tail);
    }

    // 从缓冲区中取出一个元素
    T pop(){
        if(empty()){
            throw runtime_error("buffer is empty!");
        }
        T item = m_data[m_tail];
        m_full = false;
        m_tail = (m_tail + 1) % m_data.size();
        return item;
    }    

private:
    vector<T> m_data;
    size_t m_head;
    size_t m_tail;
    bool m_full;
};

int main(){
    circularBuffer<int> buffer(5);  // 创建大小为 5 的环形缓冲区
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);
    buffer.push(5);
    cout << buffer.full() << endl;  // 输出 1
    buffer.push(6);  // 缓冲区已满，会覆盖第一个元素
    cout << buffer.pop() << endl;  // 输出 2
    buffer.push(7);
    cout << buffer.pop() << endl;  // 输出 3
    cout << buffer.pop() << endl;  // 输出 4
    cout << buffer.pop() << endl;  // 输出 5
    cout << buffer.pop() << endl;  // 输出 6
    cout << buffer.pop() << endl;  // 输出 7
    cout << buffer.pop() << endl;
}