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
        if(full()){
            m_tail = (m_tail + 1) % m_data.size();
        }
        m_data[m_head] = item;
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