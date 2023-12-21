#include <iostream>
#include <vector>

template<typename T>
class circularBuffer{
public:
    circularBuffer(int n):m_data(n), m_head(0), m_tail(0), m_full(false){}

    bool full(){
        return m_full;
    }

    bool empty(){
        return !m_full && m_head == m_tail;
    }

    void push(const T& item){
        m_data[m_head] = item;
        if(m_full){
            m_tail = (m_tail + 1) % m_data.size();
        }
        m_head = (m_head + 1) % m_data.size();
        m_full = (m_head == m_tail);
    }

    T pop(){
        if(empty()){
            throw std::runtime_error("Buffer is empty!");
        }
        T item = m_data[m_tail];
        m_tail = (m_tail + 1) % m_data.size();
        m_full = false;
        return item;
    }

private:
    std::vector<T> m_data;
    int m_head;
    int m_tail;
    bool m_full;
};


int main(){
    circularBuffer<int> buffer(5);  // 创建大小为 5 的环形缓冲区
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);
    buffer.push(5);
    std::cout << buffer.full() << std::endl;  // 输出 1
    buffer.push(6);  // 缓冲区已满，会覆盖第一个元素
    std::cout << buffer.pop() << std::endl;  // 输出 2
    buffer.push(7);
    std::cout << buffer.pop() << std::endl;  // 输出 3
    std::cout << buffer.pop() << std::endl;  // 输出 4
    std::cout << buffer.pop() << std::endl;  // 输出 5
    std::cout << buffer.pop() << std::endl;  // 输出 6
    std::cout << buffer.pop() << std::endl;  // 输出 7
    std::cout << buffer.pop() << std::endl;
}