#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class circularBuffer{
public:
    circularBuffer(size_t size): m_data(size), m_head(0), m_tail(0), m_full(false){}

    ~circularBuffer(){}

    bool full() const{
        return m_full;
    }

    bool empty() const{
        return !m_full && m_head == m_tail;
    }

    size_t size() const{
        if(!m_full){
            if(m_head >= m_tail){
                return m_head - m_tail;
            }else{
                return m_head - m_tail + m_data.size();
            }
        }
        return m_data.size();
    }

    void push(const T& item){
        m_data[m_head] = item;
        m_head = (m_head + 1) % m_data.size();
        if(m_full){
            m_tail = (m_tail + 1) % m_data.size();
        }
        m_full = (m_head == m_tail);
    }

    T pop(){
        if(empty()){
            throw runtime_error("Buffer is empty!");
        }
        T item = m_data[m_tail];
        m_tail = (m_tail + 1) % m_data.size();
        m_full = false;
        return item;
    }


private:
    vector<T> m_data;
    size_t m_head;
    size_t m_tail;
    bool m_full;
};


int main(){
    circularBuffer<int> buffer(5);
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);
    buffer.push(5);
    cout << buffer.size() << endl;

    return 0;
}