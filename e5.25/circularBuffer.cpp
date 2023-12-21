#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class circularBuffer{
public:
    circularBuffer(int size): m_data(size), m_head(0), m_tail(0), m_full(false){}

    bool full() const{
        return m_full;
    }

    bool empty() const{
        return !m_full && m_head == m_tail;
    }

    int size(){
        if(!m_full){
            if(m_head > m_tail){
                return m_head - m_tail;
            }else{
                return m_head - m_tail + m_data.size();
            }
        }
        return m_data.size();
    }

    void put(const T& data){
        if(m_full){
            m_tail = (m_tail + 1) % m_data.size();
        }
        m_data[m_head] = data;
        m_head = (m_head + 1) % m_data.size();
        m_full = (m_head == m_tail);
    }

    T pop(){
        if(empty()){
            throw runtime_error("Buffer is empty!");
        }
        T item = m_data[m_tail];
        m_tail = (m_tail + 1) % m_data.size();
        m_full = false;
        return T;
    }


private:
    vector<T> m_data;
    int m_head;
    int m_tail;
    bool m_full;
};

